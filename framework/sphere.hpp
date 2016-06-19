#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>    // A 5.6
#include "shape.hpp"
#include "ray.hpp"                  // A 5.6

class Sphere : public Shape
{
    typedef glm::vec3 vec3;
    typedef std::string str;

    public:
        Sphere() : Shape("",Color{0,0,0}), cp(vec3{0.f,0.f,0.f}), radius_(0.f)
        { std::cout << "ctor Sphere" << std::endl; }

        Sphere(vec3 const& centerpoint, float radius)
            : Shape("",Color{0,0,0})
            , cp(centerpoint)
            , radius_(radius)
        { std::cout << "ctor Sphere" << std::endl; }

        // with name and color
        Sphere(str name, vec3 const& centerpoint, float radius, Color color)
            : Shape(name,color)
            , cp(centerpoint)
            , radius_(radius)
        { std::cout << "ctor Sphere" << std::endl; }
        
        Sphere(float cp_x, float cp_y, float cp_z, float radius)
            : Shape("",Color{0,0,0})
            , cp(vec3{cp_x,cp_y,cp_z})
            , radius_(radius)
        { std::cout << "ctor Sphere" << std::endl; }

        // with name and color
        Sphere(str name, float cp_x, float cp_y, float cp_z, float radius, Color color)
            : Shape(name,color)
            , cp(vec3{cp_x,cp_y,cp_z})
            , radius_(radius)
        { std::cout << "ctor Sphere" << std::endl; }

        // 5.8
        ~Sphere() { std::cout << "dtor Sphere" << std::endl; }

        float area() const override;
        float volume() const override;

        // getter
        float getRadius() const;
        vec3 getCenter() const;

        // setter
        vec3 setCenter(vec3 const& centerpoint);
        float setRadius(float radius);

        // A 5.5
        std::ostream& print(std::ostream& os) const override;

        // A 5.6 - intersect method
        bool intersect(vec3 const& ray_orig, vec3 const& ray_dir, float& dist);
        bool intersect(Ray const& ray, float& dist);

    private:
        vec3 cp; // center point
        float radius_ = 0;
};

#endif