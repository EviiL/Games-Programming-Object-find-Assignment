#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_

#include <map>

#include <iostream>
#include <sstream>
#include <fstream>

#include "Shader.h"
#include "RawMesh.h"
#include "Texture.h"

class ResourceManager {
private:
	static ResourceManager * s_instance;

	// Private constructor, that is we do not want any actual resource manager objects. Its members and functions should be publicly available (static).
	ResourceManager() { }
	// Loads and generates a shader from file
	Shader loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile);

	std::map<std::string, Shader>    Shaders;
	std::map<std::string, Texture>   Textures;
	std::map<std::string, RawMesh>	 Meshes;
	std::string m_currentShaderIdentifier_;

public:
	static ResourceManager *getInstance()
	{

		if (s_instance == 0) {

			ResourceManager * temp = new ResourceManager();
			s_instance = temp;



		}
		// Instantiated on first use.
		return s_instance;
	}
	// Resource storage

	bool useShader(std::string pId);

	std::string getCurrentShaderID() {
		return m_currentShaderIdentifier_;
	}

	Shader LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, std::string name);
	// Retrieves a stored sader
	Shader GetShader(std::string name);

	Texture loadTexture(const GLchar *file, GLboolean alpha, std::string name);
	Texture GetTexture(std::string name);


	RawMesh * RegisterMesh(std::string pPath, RawMesh pMesh);
	RawMesh GetRawMesh(std::string pPath);

	bool checkMeshExists(std::string pPath);
};



#endif // !_RESOURCE_MANAGER_H_
