#include "box.hpp"
#include <glm/vec3.hpp>

// Oberflaeche
float Box::area() const
{
    float a = max_.y - min_.y;
    float b = max_.x - min_.x;
    float c = max_.z - min_.z;
    return (2 * (a*b + b*c + a*c));
}

float Box::volume() const
{
    float a = max_.y - min_.y;
    float b = max_.x - min_.x;
    float c = max_.z - min_.z;
    return (a * b * c);
}

// getter

glm::vec3 const& Box::getMinimum() const { return min_; }
glm::vec3 const& Box::getMaximum() const { return max_; }

// setter

void Box::setMinimum(vec3 const& min) { min_ = min; }
void Box::setMaximum(vec3 const& max) { max_ = max; }