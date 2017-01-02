#ifndef _OBJECT_LOADER_H_
#define _OBJECT_LOADER_H_

#include <vector>
#include <glm\glm.hpp>


bool LoadObject(const char * pPath,
	std::vector<glm::vec3>& vertices,
	std::vector<glm::vec2>& uvs,
	std::vector<glm::vec3>& normals
);


#endif