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
#include "sphere.hpp"
#include "box.hpp"
#include <glm/vec3.hpp>
#include <vector>


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

void Renderer::intersecting(Ray const& ray, float& dist, Color& color, glm::vec3 const& lightPos, bool lightCheck, std::vector<std::shared_ptr<Shape>> objs)
{
  float minDist = 999999;

  float sI = 0.5; // intensity
  Color shadowColor{color.r * sI, color.g * sI, color.b * sI};

  for (auto o : objs)
  {
    bool intersected = false;

    if (o->intersect(ray,dist) && o->getName() == "sp")
    {
      if (!lightCheck) {
        color = Color{1.0,0.0,0.0};
        if (dist < minDist) { minDist = dist; }

        glm::vec3 orig = ray.origin + ((dist-0.1f) * ray.normDir());
        Ray toLight{orig, lightPos - orig};
        intersecting(toLight,dist,color,lightPos,true,objs);
      }
      else {
        color = shadowColor;
      }

      intersected = true;
    }
    
    if (o->intersect(ray,dist) && o->getName() == "bx" && dist < minDist)
    {
      if (!lightCheck) {
        color = Color{0.0,0.5f,0.0};

        glm::vec3 orig = ray.origin + ((dist-0.1f) * ray.normDir());
        Ray toLight{orig, lightPos - orig};
        intersecting(toLight,dist,color,lightPos,true,objs);
      }
      else { color = shadowColor; }

      intersected = true;
    }

    if (intersected) { break; }
  }
}

void Renderer::render()
{
  const std::size_t checkersize = 20;

  int pxnum = 0;

  for (unsigned y = 0; y < height_; ++y) {
    for (unsigned x = 0; x < width_; ++x) {
      Pixel p(x,y);

      /* // Primzahlen
      int fade = 1; // = (float) pxnum / (float) (height_*width_)

      pxnum++;

      if (prim(pxnum)) { p.color = Color(fade * 1.0,0.0,0.0); }
      else { p.color = Color(0.0,0.0,0.0); }
      */
      

      // Easy ray trace test 1
      /*
      float resolution = 100.0f;
      float dist = 0;
      float fog = 6;
      float ambientBrightness = 0.2f;

      Sphere sphere{glm::vec3{3.0,3.0,5.0},1.5f};
      Box box{glm::vec3{1.0,0.1,1},glm::vec3{5.5,1,8}};
      
      Ray ray{glm::vec3{(float) x / resolution,(float) y / resolution,0}, glm::vec3{0.1,-0.1,1.0f}};

      if (sphere.intersect(ray,dist))
      {
        float mult = 1-(dist/fog);
        if (mult < ambientBrightness) { mult = ambientBrightness; }
        p.color = Color{mult * 1.0f,0.0,0.0};
      }
      else if (box.intersect(ray,dist))
      {
        float mult = 1-(dist/fog);
        if (mult < ambientBrightness) { mult = ambientBrightness; }
        p.color = Color{0.0,mult * 0.5f,0.0};
      }
      else { p.color = Color{0.0,0.0,0.0}; }
      */


      // A bit more advanced raytrace test 2
      auto sphere = std::make_shared<Sphere>(Sphere{"sp",glm::vec3{3,4.0,3.0},2.0f});
      auto box = std::make_shared<Box>(Box{"bx",glm::vec3{2.0,-2.0,1},glm::vec3{4,0,1.5}});
      auto box2 = std::make_shared<Box>(Box{"bx",glm::vec3{-3.0,-3.0,1},glm::vec3{-1,-1,1.5}});
      
      std::vector<std::shared_ptr<Shape>> objects{sphere, box, box2};

      float resolution = 100.0f;
      float dist = 0;
      float fov = 0.6;

      Ray ray{glm::vec3{0, 0, 0}, glm::vec3{(float) x / resolution - ((float) width_ / resolution / 2.0f),(float) y / resolution - ((float) height_ / resolution / 2.0f),fov}};
      
      // background color
      p.color = Color{0.1,0.1,0.1};

      // light pos
      glm::vec3 lp{0.0f,0.0f,0.0f};

      intersecting(ray, dist, p.color, lp, false, objects);

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
