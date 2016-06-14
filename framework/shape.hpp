#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include "color.hpp"

class Shape
{
    typedef std::string str;

    public:
        Shape() : name_(""), color_(Color{0,0,0}) {}

        Shape(str name, Color color) : name_(name), color_(color) {}

        virtual float area() const = 0;
        virtual float volume() const = 0;

        str getName() const;
        Color getColor() const;
    
    protected:
        str name_;
        Color color_;
};

#endif