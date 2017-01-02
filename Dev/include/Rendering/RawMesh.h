#ifndef _RAW_MESH_H_
#define _RAW_MESH_H_

#include <gl\glew.h>
#include <vector>


struct RawMesh{

	GLuint * VAO;
	bool m_hasUVData_;

	int m_drawSize_;

	RawMesh() {

	}

	RawMesh(std::vector<GLfloat> vertices);
	RawMesh(std::vector<GLfloat> vertices, std::vector<GLfloat> UV);
};

#endif