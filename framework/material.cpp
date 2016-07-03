#include "material.hpp"

Material::Material() : name_{"Material"}, ka_{0.0f,0.0f,0.0f}, kd_{0.0f,0.0f,0.0f}, ks_{0.0f,0.0f,0.0f}, m_{0.0f} {}

Material::Material(std::string const& name, Color const& ka, Color const& kd, Color const& ks, float m)
                  : name_{name}
                  , ka_{ka}
                  , kd_{kd}
                  , ks_{ks}
                  , m_{m}
                  {}

std::ostream& Material::print(std:: ostream& os) const
{
    os << "Name: " << name_ << "\n"
       << "Ambient: " << ka_
       << "Diffuse: " << kd_
       << "Specular: " << ks_
       << "Exponent: " << m_
    << std::endl;
    return os;
}

Color const& Material::ambient() const { return ka_; }

Color const& Material::diffuse() const { return kd_; }

Color const& Material::specular() const { return ks_; }

float Material::exponent() const { return m_; }

std::ostream& operator<<(std::ostream& os, Material const& mat)
{ return mat.print(os); }