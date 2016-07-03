#define M_PI 3.14159265358979323846 // pi
#include <cmath>
#include "sphere.hpp"

// Constructor
Sphere::Sphere() : Shape("",Material{}), cp(vec3{0.f,0.f,0.f}), radius_(0.f) {}

Sphere::Sphere(vec3 const& centerpoint, float radius)
              : Shape("",Material{})
              , cp(centerpoint)
              , radius_(radius)
              {}

Sphere::Sphere(str const& name, vec3 const& centerpoint, float radius, Material const& material)
              : Shape(name,material)
              , cp(centerpoint)
              , radius_(radius)
              {}

Sphere::Sphere(float cp_x, float cp_y, float cp_z, float radius)
              : Shape("",Material{})
              , cp(vec3{cp_x,cp_y,cp_z})
              , radius_(radius)
              {}

Sphere::Sphere(str const& name, float cp_x, float cp_y, float cp_z, float radius, Material const& material)
              : Shape(name,material)
              , cp(vec3{cp_x,cp_y,cp_z})
              , radius_(radius)
              {}


// Oberflaeche - 4 * PI * r^2
float Sphere::area() const
{
    return (4.0f * M_PI * (radius_ * radius_));
}

// Volumen 4/3 * PI * r^3
float Sphere::volume() const
{
    return ((4.0f/3.0f) * M_PI * (radius_ * radius_ * radius_));
}


// getter

float Sphere::getRadius() const { return radius_; }
glm::vec3 Sphere::getCenter() const { return cp; }


// setter

glm::vec3 Sphere::setCenter(vec3 const& centerpoint) { cp = centerpoint; }
float Sphere::setRadius(float radius) { radius_ = radius; }


// console output

std::ostream& Sphere::print(std::ostream& os) const
{
    return (os << "-----------------------------------\n"
               << "Type:\tSphere" << "\n\n"
               << "Name:\t" << name_ << "\n"
               << "Center:\tx: " << cp.x << ", y: " << cp.y << ", z: " << cp.z << "\n"
               << "Radius:\t" << radius_ << "\n\n"
               << "Area:\t" << area() << "\n"
               << "Volume:\t" << volume() << "\n"
               << "-----------------------------------\n");
}

bool Sphere::intersect(Ray const& ray, float& dist) const
{
    glm::vec3 dirNorm = ray.normDir();
    return glm::intersectRaySphere(ray.origin, dirNorm, cp, radius_ * radius_, dist);
}