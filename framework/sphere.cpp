#define M_PI 3.14159265358979323846 // pi
#include <cmath>
#include "sphere.hpp"

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
               << "Color:\tr: " << color_.r << ", g: " << color_.g << ", b: " << color_.b << "\n"
               << "Center:\tx: " << cp.x << ", y: " << cp.y << ", z: " << cp.z << "\n"
               << "Radius:\t" << radius_ << "\n\n"
               << "Area:\t" << area() << "\n"
               << "Volume:\t" << volume() << "\n"
               << "-----------------------------------\n");
}

// Aufgabe 5.6

glm::vec3 rayAsVec(glm::vec3 const& ray_orig, glm::vec3 const& ray_dir)
{
    return glm::vec3{ray_orig.x + ray_dir.x, ray_orig.y + ray_dir.y, ray_orig.z + ray_dir.z};
}

bool Sphere::intersect(glm::vec3 const& ray_orig, glm::vec3 const& ray_dir, float& dist)
{
    glm::vec3 dirNorm = rayAsVec(ray_orig, ray_dir);

    // normalize ray if it isnt yet
    if (glm::length(dirNorm) != 1.0)
    { dirNorm *= (1.0 / glm::length(dirNorm)); }

    return glm::intersectRaySphere(ray_orig, dirNorm, cp, radius_ * radius_, dist);
}

bool Sphere::intersect(Ray const& ray, float& dist)
{
    return intersect(ray.origin, ray.direction, dist);
}