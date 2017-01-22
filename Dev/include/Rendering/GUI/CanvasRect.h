#ifndef _CANVAS_ELEMENT_RECT_H_
#define _CANVAS_ELEMENT_RECT_H_

#include "CanvasElement.h"
#include "GUIMesh.h"

#include <glm\gtc\matrix_transform.hpp>

class CanvasRect : public CanvasElement {

private:

	GUIMesh m_Mesh_;
	glm::vec4 m_Colour_;


	glm::mat4 m_Model_;

public:

	CanvasRect(CanvasElement * pParent, glm::vec4 pColour) {
		m_Parent_ = pParent;
		m_Colour_ = pColour;

		m_Mesh_ = GUIMesh(GL_STATIC_DRAW);
	}
	void Start();

	void Update(float dt);

	void Render();


	void Destroy();







};

#endif