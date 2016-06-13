#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"

class Sphere : public Shape
{
    public:
        Sphere() : cp(glm::vec3{0f,0f,0f}), radius_(0f) {}
        Sphere(glm::vec3 const& centerpoint, float radius) : cp(centerpoint), radius_(radius) {}

        float area() const;
        float volume() const;

        // getter
        float getRadius() const;
        glm::vec3 getCenter() const;

        // setter
        glm::vec3 setCenter();
        float setRadius();

    private:
        glm::vec3 cp; // center point
        float radius_ = 0;
};

#endif