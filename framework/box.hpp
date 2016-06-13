#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"

class Box : public Shape
{
    typedef glm::vec3 vec3;

    public:
    	Box() : min_(vec3{0.f,0.f,0.f}), max_(vec3{0.f,0.f,0.f}) {}

    	Box(vec3 const& min, vec3 const& max) : min_(min), max_(max) {}

        Box(float min_x, float min_y, float min_z, float max_x, float max_y, float max_z)
            : min_(vec3{min_x,min_y,min_z})
            , max_(vec3{max_x,max_y,max_z})
        {}
        
        float area() const override;
        float volume() const override;

        // getter
        vec3 const& getMinimum() const;

        // setter
        void setMinimum(vec3 const& min) { min_ = min; }

    private:
        vec3 min_;
        vec3 max_;
};

#endif