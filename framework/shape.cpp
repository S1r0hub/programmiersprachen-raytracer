#include "shape.hpp"

// Constructor
Shape::Shape() : name_(""), color_(Color{0,0,0}) { /*std::cout << "ctor Shape" << std::endl;*/ }
Shape::Shape(str name, Color color) : name_(name), color_(color) { /*std::cout << "ctor Shape" << std::endl;*/ }


// Getter and Setter
std::string const& Shape::getName() const { return name_; }

Color const& Shape::getColor() const { return color_; }

std::ostream& Shape::print(std::ostream& os) const
{
    return (os << "-----------------------------------\n"
               << "I have no own print function :(\n"
               << "But I am: \"" << name_ << "\"\n"
               << "I got the Color: " << color_.r << "," << color_.g << "," << color_.b << "\n\n"
               << "Area:\t" << area() << "\n"
               << "Volume:\t" << volume() << "\n"
               << "-----------------------------------\n");
}

std::ostream& operator<<(std::ostream& os, Shape const& s)
{ return s.print(os); }