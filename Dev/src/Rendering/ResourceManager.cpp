#include "Rendering\ResourceManager.h"

#include "Rendering\MeshFactory.h"

ResourceManager * ResourceManager::s_instance = 0;

Shader ResourceManager::loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile)
{
	// 1. Retrieve the vertex/fragment source code from filePath
	std::string vertexCode;
	std::string fragmentCode;
	std::string geometryCode;
	try
	{
		// Open files
		std::ifstream vertexShaderFile(vShaderFile);
		std::ifstream fragmentShaderFile(fShaderFile);
		std::stringstream vShaderStream, fShaderStream;
		// Read file's buffer contents into streams
		vShaderStream << vertexShaderFile.rdbuf();
		fShaderStream << fragmentShaderFile.rdbuf();
		// close file handlers
		vertexShaderFile.close();
		fragmentShaderFile.close();
		// Convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::exception e)
	{
		std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
	}
	const GLchar *vShaderCode = vertexCode.c_str();
	const GLchar *fShaderCode = fragmentCode.c_str();
	const GLchar *gShaderCode = geometryCode.c_str();
	// 2. Now create shader object from source code
	Shader shader;
	shader.Compile(vShaderCode, fShaderCode);
	return shader;
}

bool ResourceManager::useShader(std::string pId) {

	//Try to find the shader, and if so, use it, otherwise return false to prevent error.
	auto iter = Shaders.find(pId);
	if (iter != Shaders.end())
	{
		// key 2 exists, do something with iter->second (the value)
		iter->second.Use();
		m_currentShaderIdentifier_ = pId;
		return true;
	}
	return false;
}

Shader ResourceManager::LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, std::string name)
{
	Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile);
	return Shaders[name];
}

Shader ResourceManager::GetShader(std::string name)
{
	return Shaders[name];
}

RawMesh * ResourceManager::RegisterMesh(std::string pPath, RawMesh pMesh) {
	MeshFactory factory;
	
	Meshes[pPath] = pMesh;
	//Mesh * meshPointer = &Meshes[pPath];

	return &Meshes[pPath];
}

RawMesh ResourceManager::GetRawMesh(std::string pPath) {
	return Meshes[pPath];
}

bool ResourceManager::checkMeshExists(std::string pPath) {
	auto iter = Meshes.find(pPath);
	if (iter != Meshes.end())
	{

		if (iter->first == pPath) {
			return true;
		}
	}
	return false;
}



