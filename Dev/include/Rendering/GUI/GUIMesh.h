#ifndef _GUI_MESH_H_
#define _GUI_MESH_H_

#include <gl\glew.h>
#include <vector>

struct GUIMesh {

	GLuint * VAO;

	//GLfloat GUIMesh::vertices[6 * 4] = {
	//	// Pos      // Tex


	//	0.0f, 1.0f, 0.0f, 1.0f,
	//	1.0f, 0.0f, 1.0f, 0.0f,
	//	0.0f, 0.0f, 0.0f, 0.0f,

	//	0.0f, 1.0f, 0.0f, 1.0f,
	//	1.0f, 1.0f, 1.0f, 1.0f,
	//	1.0f, 0.0f, 1.0f, 0.0f


	//};
	GUIMesh() {}

	GUIMesh(int pDrawtype, std::vector<GLfloat> verts = {
		// Pos      // Tex


		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f


	});





};

#endif
