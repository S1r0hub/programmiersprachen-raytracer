#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"

class Sphere : public Shape
{
    public:
        float area() const;
        float volume() const;

        // Getter
        float getRadius() const;
        glm::vec3 getCenter() const;

        // Setter
        glm::vec3 setCenter();
        float setRadius();

    private:
        glm::vec3 cp; // center point
        float radius = 0;
};

#endif