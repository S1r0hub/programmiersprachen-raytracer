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


// using Shirley's algorithm
bool Box::intersect(Ray const& ray, float& t) const
{
    glm::vec3 dirNorm = ray.normDir();

    float tmin = 0;
    float tmax = 0;

    for (int i = 0; i < 3; ++i)
    {
        float invDir = 1.0f / dirNorm[i];
        float t0 = (min_[i] - ray.origin[i]) * invDir;
        float t1 = (max_[i] - ray.origin[i]) * invDir;

        if (invDir < 0.0f) { std::swap(t0,t1); }

        tmin = (t0 > tmin) ? t0 : tmin;
        tmax = (t1 < tmax) ? t1 : tmax;

        std::cout << "TMIN: " << tmin << "\nTMAX: " << tmax << std::endl;

        if (tmax < tmin) { return false; }
    }

    return true;
}