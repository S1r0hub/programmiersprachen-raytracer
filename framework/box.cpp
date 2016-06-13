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