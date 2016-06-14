#include "shape.hpp"

std::string Shape::getName() const { return name_; }

Color Shape::getColor() const { return color_; }

std::ostream& Shape::print(std::ostream& os) const
{
	return os << "Name:\t" << name_ << "\n";
}