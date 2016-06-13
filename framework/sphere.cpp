#define M_PI 3.14159265358979323846 // pi
#include <cmath>
#include <iostream>
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