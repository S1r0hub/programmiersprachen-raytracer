#include "box.hpp"

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


// console output

std::ostream& Box::print(std::ostream& os) const
{
    return (os << "-----------------------------------\n"
               << "Type:\tBox" << "\n\n"
               << "Name:\t" << name_ << "\n"
               << "Color:\tr: " << color_.r << ", g: " << color_.g << ", b:" << color_.b << "\n"
               << "Min:\tx: " << min_.x << ", y: " << min_.y << ", z: " << min_.z << "\n"
               << "Max:\tx: " << max_.x << ", y: " << max_.y << ", z: " << max_.z << "\n\n"
               << "Area:\t" << area() << "\n"
               << "Volume:\t" << volume() << "\n"
               << "-----------------------------------\n");
}