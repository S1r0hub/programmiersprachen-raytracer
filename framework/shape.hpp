#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <iostream>
#include "color.hpp"

class Shape
{
    typedef std::string str;

    public:
        Shape() : name_(""), color_(Color{0,0,0}) { std::cout << "ctor Shape" << std::endl; }

        Shape(str name, Color color) : name_(name), color_(color) { std::cout << "ctor Shape" << std::endl; }

        // 5.8 - test 1
        //virtual ~Shape() { std::cout << "dtor Shape" << std::endl; }
        // 5.8 - test 2
        ~Shape() { std::cout << "dtor Shape" << std::endl; }

        virtual float area() const = 0;
        virtual float volume() const = 0;

        virtual std::ostream& print(std::ostream& os) const;

        str getName() const;
        Color getColor() const;
    
    protected:
        str name_;
        Color color_;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif