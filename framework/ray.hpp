#ifndef RAY_HPP
#define RAY_HPP

#include <glm/vec3.hpp>

struct Ray
{
	glm::vec3 origin;
	glm::vec3 direction;

	glm::vec3 const normDir() const
	{
    	glm::vec3 dirNorm = direction;
    	dirNorm *= (1.0 / glm::length(dirNorm));
    	return dirNorm;
	}
};

#endif