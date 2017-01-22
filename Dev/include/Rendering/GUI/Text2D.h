#ifndef _TEXT_2D_H_
#define _TEXT_2D_H_

#include <iostream>

#include "CanvasElement.h"

#define ROWS 8
#define COLUMNS 16




class Text2D : public CanvasElement {
private:

	std::string m_Text_;

	GLuint quadVAO;
	GLuint VBO;

	bool usesID = false;


public:
	Text2D(std::string pShader, std::string pText);
	void print(std::string pText, int pX, int pY, int pSize);

	void setUsesID(bool pToggle) {
		usesID = pToggle;
	}
	void Start();

	void Update(float dt);

	void Render();
	void Destroy();
};

#endif