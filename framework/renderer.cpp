// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#include "renderer.hpp"

#include <iostream>
#include <cmath>
#include "ray.hpp"
#include "sphere.hpp"
#include <glm/vec3.hpp>


Renderer::Renderer(unsigned w, unsigned h, std::string const& file)
  : width_(w)
  , height_(h)
  , colorbuffer_(w*h, Color(0.0, 0.0, 0.0))
  , filename_(file)
  , ppm_(width_, height_)
{}


int ggT(int a, int b)
{
    if (a == 1 || b == 1) { return 1; }
    else
    {
        int c = 0;

        while (b != 0)
        {
            c = b;
            b = a % b;
            a = c;
        }

        return a;
    }
}

bool prim(int z)
{
    if (z == 1) { return false; }
    else if (z == 2) { return true; }
    else if (z % 2 == 0 || z == 1) { return false; }
    else
    {
        for (int i = 3; i <= sqrt(z); i = i + 2)
        { if (ggT(z,i) != 1) { return false; } }

        return true;
    }
}

void Renderer::render()
{
  const std::size_t checkersize = 20;

  int pxnum = 0;

  std::cout << prim(15) << std::endl;

  for (unsigned y = 0; y < height_; ++y) {
    for (unsigned x = 0; x < width_; ++x) {
      Pixel p(x,y);

      /* // Primzahlen
      int fade = 1; // = (float) pxnum / (float) (height_*width_)

      pxnum++;

      if (prim(pxnum)) { p.color = Color(fade * 1.0,0.0,0.0); }
      else { p.color = Color(0.0,0.0,0.0); }
      */
      
      // Sphere
      Sphere sphere{glm::vec3{5.0,5.0,5.0},1.0f};
      Ray ray{glm::vec3{(float) x / 100.0f,(float) y / 100.0f,0}, glm::vec3{0,0,1.0f}};
      float dist = 0;

      if (sphere.intersect(ray,dist)) { p.color = Color{1.0,0.0,0.0}; }
      else { p.color = Color{0.0,0.0,0.0}; }
      
      write(p);
    }
  }
  ppm_.save(filename_);
}

void Renderer::write(Pixel const& p)
{
  // flip pixels, because of opengl glDrawPixels
  size_t buf_pos = (width_*p.y + p.x);
  if (buf_pos >= colorbuffer_.size() || (int)buf_pos < 0) {
    std::cerr << "Fatal Error Renderer::write(Pixel p) : "
      << "pixel out of ppm_ : "
      << (int)p.x << "," << (int)p.y
      << std::endl;
  } else {
    colorbuffer_[buf_pos] = p.color;
  }

  ppm_.write(p);
}
