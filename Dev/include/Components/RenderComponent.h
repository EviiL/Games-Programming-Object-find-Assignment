#ifndef _RENDER_COMPONENT_H_
#define _RENDER_COMPONENT_H_

#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

#include "Component.h"
#include "Rendering\Mesh.h"
#include "Components\TransformComponent.h"

enum ComponentType {
	COLOUR,
	TEXTURE
};

class RenderComponent : public Component {

private:

	typedef std::vector<Mesh*> t_Mesh_vector_;
	typedef t_Mesh_vector_::iterator t_Mesh_vector_Iterator_;


	std::string m_Shader_;
	t_Mesh_vector_ m_Meshes_;
	TransformComponent* transformComponent;

	int m_RenderType_;


public:

	RenderComponent(GameObject * pParent, std::string sShader, int pType = COLOUR);

	void Update(double dt);
	void LateUpdate(double dt);

	void Destroy();
	void Start();

	void AttachMesh(Mesh* pMesh);
	void Render(glm::mat4 pProj, glm::mat4 pView);
};





#endif 
