#ifndef _XML_PARSER_H_
#define _XML_PARSER_H_


#include <tinyxml2.h>

#include <iostream>
#include <vector>
#include <Scene.h>

#include "Components\Components.h"
#include "Rendering\GUI\Text2D.h"

using namespace tinyxml2;

class XMLParser {


private:
	XMLDocument m_Doc_;
	XMLNode * m_Root_;
public:

	XMLParser();
	bool Parse(std::string pPath);

	std::vector<XMLElement*> GetElements(std::string filter);

	Scene * LoadScene();

	void ProcessComponent(Scene * pScene, XMLElement * pElement, int pIndex);
	void ProcessCanvas(Scene * pScene, XMLElement * pElement, int pIndex);


	glm::vec3 GenerateVec3(XMLElement * element);
	glm::vec4 GenerateVec4(XMLElement * element);


	bool checkStrings(const char* s1, const char* s2) {
		if (std::strcmp(s1, s2) == 0)
			return true;
		else
			return false;
	}
};




#endif