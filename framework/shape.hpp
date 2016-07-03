#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <iostream>
#include "color.hpp"
#include "ray.hpp"

class Shape
{
    typedef std::string str;

    public:
        Shape();

        Shape(str name, Color color);

        // 5.8 - test 1
        //virtual ~Shape() { std::cout << "dtor Shape" << std::endl; }
        // 5.8 - test 2
        ~Shape() { /*std::cout << "dtor Shape" << std::endl;*/ }

        virtual float area() const = 0;
        virtual float volume() const = 0;

        virtual std::ostream& print(std::ostream& os) const;

        str const& getName() const;
        Color const& getColor() const;

        // 6.3
        virtual bool intersect(Ray const& ray, float& t) const = 0;
    
    protected:
        str name_;
        Color color_;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif