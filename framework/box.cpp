#include "box.hpp"
#include <utility> // for std::swap

// Constructor
Box::Box() : Shape("",Material{}), min_(vec3{0.f,0.f,0.f}), max_(vec3{0.f,0.f,0.f}) { /*std::cout << "ctor Box" << std::endl;*/ }

Box::Box(vec3 const& min, vec3 const& max) : Shape("",Material{}), min_(min), max_(max) { /*std::cout << "ctor Box" << std::endl;*/ }

Box::Box(str const& name, vec3 const& min, vec3 const& max, Material const& material )
        : Shape(name,material)
        , min_(min)
        , max_(max)
        {}

Box::Box(float min_x, float min_y, float min_z, float max_x, float max_y, float max_z)
        : Shape("",Material{})
        , min_(vec3{min_x,min_y,min_z})
        , max_(vec3{max_x,max_y,max_z})
        {}

Box::Box(str const& name, float min_x, float min_y, float min_z, float max_x, float max_y, float max_z, Material const& material)
        : Shape(name,material)
        , min_(vec3{min_x,min_y,min_z})
        , max_(vec3{max_x,max_y,max_z})
        {}


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
               << "Min:\tx: " << min_.x << ", y: " << min_.y << ", z: " << min_.z << "\n"
               << "Max:\tx: " << max_.x << ", y: " << max_.y << ", z: " << max_.z << "\n\n"
               << "Area:\t" << area() << "\n"
               << "Volume:\t" << volume() << "\n"
               << "-----------------------------------\n");
}


/*
// algorithm from:
// http://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-box-intersection

bool Box::intersect(Ray const& ray, float& t) const
{
    //glm::vec3 dirNorm = ray.normDir();
    glm::vec3 dirNorm = ray.direction;

    float txMin = (min_.x - ray.origin.x) / dirNorm.x;
    float txMax = (max_.x - ray.origin.x) / dirNorm.x;

    // Tausche txMin und txMax, falls Min > Max
    if (txMin > txMax) std::swap(txMin, txMax);

    float tyMin = (min_.y - ray.origin.y) / dirNorm.y;
    float tyMax = (max_.y - ray.origin.y) / dirNorm.y;

    // Tausche tyMin und tyMax, falls Min > Max
    if (tyMin > tyMax) { std::swap(tyMin, tyMax); }

    // Kein Schnitt
    if ((txMin > tyMax) || (tyMin > txMax)) { return false; }

    if (tyMin > txMin) { txMin = tyMin; }
    if (tyMax < txMax) { txMax = tyMax; }

    float tzMin = (min_.z - ray.origin.z) / dirNorm.z;
    float tzMax = (max_.z - ray.origin.z) / dirNorm.z;

    // Tausche tzMin und tzMax, falls Min > Max
    if (tzMin > tzMax) std::swap(tzMin, tzMax);

    // Kein Schnitt
    if ((txMin > tzMax) || (tzMin > txMax)) { return false; }

    if (tzMin > txMin) { txMin = tzMin; }
    if (tzMax < txMax) { txMax = tzMax; }

    // Schnitt vorhanden
    return true;
}
*/

// Shirley's algorithm
// http://psgraphics.blogspot.de/2016/02/new-simple-ray-box-test-from-andrew.html

bool Box::intersect(Ray const& ray, float& t) const
{
    float tmin = -std::numeric_limits<float>::infinity();
    float tmax = std::numeric_limits<float>::infinity();

    glm::vec3 normDir = ray.normDir();

    for (int i = 0; i < 3; ++i)
    {
        float invDiv = 1.0f / normDir[i];
        float t0 = (min_[i] - ray.origin[i]) * invDiv;
        float t1 = (max_[i] - ray.origin[i]) * invDiv;

        if (invDiv < 0.0f) { std::swap(t0,t1); }

        tmin = t0 > tmin ? t0 : tmin;
        tmax = t1 < tmax ? t1 : tmax;

        if (tmax < tmin) { return false; }

        t = tmin;
    }

    return true;
}