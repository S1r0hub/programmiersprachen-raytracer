#include "shape.hpp"

// Constructor
Shape::Shape() : name_(""), material_(Material{}) {}

Shape::Shape(str name, Material material) : name_(name), material_(material) {}


// Getter and Setter
std::string const& Shape::getName() const { return name_; }

Material const& Shape::getMaterial() const { return material_; }

std::ostream& Shape::print(std::ostream& os) const
{
    return (os << "-----------------------------------\n"
               << "I have no own print function :(\n"
               << "But I am: \"" << name_ << "\"\n"
               << "Area:\t" << area() << "\n"
               << "Volume:\t" << volume() << "\n"
               << "-----------------------------------\n");
}

std::ostream& operator<<(std::ostream& os, Shape const& s)
{ return s.print(os); }