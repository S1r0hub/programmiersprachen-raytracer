#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <iostream>
// #include "color.hpp"
#include "material.hpp" // 6.4
#include "ray.hpp"

class Shape
{
    typedef std::string str;

    public:
        Shape();

        Shape(str const& name, Material const& material);

        //~Shape() {}

        virtual float area() const = 0;
        virtual float volume() const = 0;

        virtual std::ostream& print(std::ostream& os) const;

        str const& getName() const;
        Material const& getMaterial() const;

        // 6.3
        virtual bool intersect(Ray const& ray, float& t) const = 0;
    
    protected:
        str name_;
        Material material_;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif