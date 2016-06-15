#include "shape.hpp"

std::string Shape::getName() const { return name_; }

Color Shape::getColor() const { return color_; }

std::ostream& Shape::print(std::ostream& os) const
{
	return (os << "My own print function is not implemented yet :(\n"
			   << "But I am: \"" << name_ << "\"\n"
			   << "I got the Color: " << color_.r << "," << color_.g << "," << color_.b << "\n");
}