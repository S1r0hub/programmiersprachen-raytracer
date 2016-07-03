#ifndef RAY_HPP
#define RAY_HPP

#include <glm/vec3.hpp>

struct Ray
{
	glm::vec3 origin;
	glm::vec3 direction;

	// get single vector style
	glm::vec3 const vector() const
	{ return glm::vec3{origin.x + direction.x, origin.y + direction.y, origin.z + direction.z}; }

	glm::vec3 const normDir() const
	{
    	glm::vec3 dirNorm = vector();
    	dirNorm *= (1.0 / glm::length(dirNorm));
    	return dirNorm;
	}
};

#endif