#ifndef SCENE_HPP
#define SCENE_HPP

#include <map>
#include <string>
#include <memory>
#include "material.hpp"
#include "shape.hpp"

struct Scene
{
	std::vector<std::shared_ptr<Shape>> shapes;
	std::map<std::string,Material> materials;
};

#endif