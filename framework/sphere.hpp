#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>    // A 5.6
#include "shape.hpp"

class Sphere : public Shape
{
    typedef glm::vec3 vec3;
    typedef std::string str;

    public:
        Sphere();

        Sphere(vec3 const& centerpoint, float radius);

        // with name and material
        Sphere(str const& name, vec3 const& centerpoint, float radius, Material const& material = Material{});
        
        Sphere(float cp_x, float cp_y, float cp_z, float radius);

        // with name and material
        Sphere(str const& name, float cp_x, float cp_y, float cp_z, float radius, Material const& material = Material{});

        //~Sphere() {}

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
        bool intersect(Ray const& ray, float& dist) const override;

    private:
        vec3 cp; // center point
        float radius_ = 0;
};

#endif