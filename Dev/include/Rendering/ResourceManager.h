#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_

#include <map>

#include <iostream>
#include <sstream>
#include <fstream>

#include <functional>


#include "Shader.h"
#include "RawMesh.h"
#include "Texture.h"

struct Character {
	GLfloat x, y, w, h;
	GLint textureID;
};

class ResourceManager {

	typedef std::function< void(void) > t_Click_Handler;
private:
	static ResourceManager * s_instance;

	// Private constructor, that is we do not want any actual resource manager GameObjects. Its members and functions should be publicly available (static).
	ResourceManager() { }
	// Loads and generates a shader from file
	Shader loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile);

	std::map<std::string, Shader>    Shaders;
	std::map<std::string, Texture>   Textures;
	std::map<std::string, RawMesh>	 Meshes;
	std::map<GLchar, Character> Characters;
	std::map<std::string, t_Click_Handler> buttonClickFunctions;
	std::map<std::string, std::string> textIdentifiers;

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

	Character getCharacter(GLchar pChar){
		return Characters[pChar];
	}

	std::string getText(std::string pKey) {
		return textIdentifiers[pKey];
	}

	void assignTextIdentifier(std::string pKey, std::string pValue) {
		textIdentifiers[pKey] = pValue;
	}


	void setupTextCharacters(std::string pFont);

	bool checkMeshExists(std::string pPath);

	void attachButtonFunction(std::string pID, t_Click_Handler pClick) {
		buttonClickFunctions[pID] = pClick;
	}

	t_Click_Handler getButtonFunctions(std::string pFunction) {
		return buttonClickFunctions[pFunction];
	}

};



#endif // !_RESOURCE_MANAGER_H_
