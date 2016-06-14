#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <string>
#include "shape.hpp"
#include "color.hpp"

class Sphere : public Shape
{
    typedef glm::vec3 vec3;
    typedef std::string str;

    public:
        Sphere() : Shape("",Color{0,0,0}), cp(vec3{0.f,0.f,0.f}), radius_(0.f) {}

        Sphere(vec3 const& centerpoint, float radius)
            : Shape("",Color{0,0,0})
            , cp(centerpoint)
            , radius_(radius)
        {}

        // with name and color
        Sphere(str name, vec3 const& centerpoint, float radius, Color color)
            : Shape(name,color)
            , cp(centerpoint)
            , radius_(radius)
        {}
        
        Sphere(float cp_x, float cp_y, float cp_z, float radius)
            : Shape("",Color{0,0,0})
            , cp(vec3{cp_x,cp_y,cp_z})
            , radius_(radius)
        {}

        // with name and color
        Sphere(str name, float cp_x, float cp_y, float cp_z, float radius, Color color)
            : Shape(name,color)
            , cp(vec3{cp_x,cp_y,cp_z})
            , radius_(radius)
        {}

        float area() const override;
        float volume() const override;

        // getter
        float getRadius() const;
        vec3 getCenter() const;

        // setter
        vec3 setCenter(vec3 const& centerpoint);
        float setRadius(float radius);

    private:
        vec3 cp; // center point
        float radius_ = 0;
};

#endif