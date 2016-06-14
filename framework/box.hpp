#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include <string>
#include "shape.hpp"
#include "color.hpp"

class Box : public Shape
{
    typedef glm::vec3 vec3;
    typedef std::string str;

    public:
    	Box() : Shape("",Color{0,0,0}), min_(vec3{0.f,0.f,0.f}), max_(vec3{0.f,0.f,0.f}) {}

        Box(vec3 const& min, vec3 const& max) : Shape("",Color{0,0,0}), min_(min), max_(max) {}

        // with name and color
    	Box(str name, vec3 const& min, vec3 const& max, Color color) : Shape(name,color), min_(min), max_(max) {}

        Box(float min_x, float min_y, float min_z, float max_x, float max_y, float max_z)
            : Shape("",Color{0,0,0})
            , min_(vec3{min_x,min_y,min_z})
            , max_(vec3{max_x,max_y,max_z})
        {}

        // with name and color
        Box(str name, float min_x, float min_y, float min_z, float max_x, float max_y, float max_z, Color color)
            : Shape(name,color)
            , min_(vec3{min_x,min_y,min_z})
            , max_(vec3{max_x,max_y,max_z})
        {}
        
        float area() const override;
        float volume() const override;

        // getter
        vec3 const& getMinimum() const;
        vec3 const& getMaximum() const;

        // setter
        void setMinimum(vec3 const& min);
        void setMaximum(vec3 const& min);

    private:
        vec3 min_;
        vec3 max_;
};

#endif