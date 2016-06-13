#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"

class Box : public Shape
{
    public:
        float area() const;
        float volume() const;

    private:
        glm::vec3 min;
        glm::vec3 max;
};

#endif