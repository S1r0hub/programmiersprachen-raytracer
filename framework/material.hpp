#ifndef BUW_MATERIAL_HPP
#define BUW_MATERIAL_HPP
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <string>
#include "color.hpp"

struct Material
{
    Material();
    Material(std::string const& name, Color const& ka, Color const& kd, Color const& ks, float e);

    std::ostream& print(std::ostream& os) const;
    Color const& ambient() const;
    Color const& diffuse() const;
    Color const& specular() const;
    float exponent() const;

    std::string name_;
    Color ka_;
    Color kd_;
    Color ks_;
    float e_;

};

std::ostream& operator<<(std::ostream& os, Material const& mat);

#endif