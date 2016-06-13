#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"

class Box : public Shape
{
    public:
    	Box() : min_(glm::vec3{0f,0f,0f}), max_(glm::vec3{0f,0f,0f})
    	Box(glm::vec3 min, glm::vec3 max) : min_(min), max_(max) {}
        
        float area() const;
        float volume() const;

        // getter
        glm::vec3 const& getMinimum() const;

        // setter
        void setMinimum(glm::vec3 const& min) { min_ = min; }

    private:
        glm::vec3 min_;
        glm::vec3 max_;
};

#endif