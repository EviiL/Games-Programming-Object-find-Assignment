#include "Components\RenderComponent.h"
#include "Rendering\ResourceManager.h"

RenderComponent::RenderComponent(Object * pParent, std::string sShader) {
	m_ObjectParent_ = pParent;
	m_Shader_ = sShader;

	transformComponent = m_ObjectParent_->GetComponentByType<TransformComponent>();

	M_ComponentName = "RENDER_COMPONENT";
}

void RenderComponent::Update(double dt) {
	//if (ResourceManager::getInstance()->getCurrentShaderID() != m_Shader_) {
	//	ResourceManager::getInstance()->useShader(m_Shader_); //Error check for false shader switch.
	//}

	//Update the values of the GPU here or do it in the render?


}
void RenderComponent::LateUpdate(double dt) {

}

void RenderComponent::Destroy() {

}

void RenderComponent::Start() {

}

void RenderComponent::AttachMesh(Mesh * pMesh) {
	m_Meshes_.push_back(pMesh);
}


void RenderComponent::Render(glm::mat4 pProj, glm::mat4 pView) {
	//No point processing rendering if no mesh is found, altho this is unlikely as no render component would be included.
	if (m_Meshes_.size() > 0) {
		if (ResourceManager::getInstance()->getCurrentShaderID() != m_Shader_) {
			ResourceManager::getInstance()->useShader(m_Shader_); //Error check for false shader switch.
		}

		//Set the Projection and View Matrices. 
		ResourceManager::getInstance()->GetShader(m_Shader_).SetMatrix4("mProjection", pProj);
		ResourceManager::getInstance()->GetShader(m_Shader_).SetMatrix4("mView", pView);

		//Set a default colour.
		ResourceManager::getInstance()->GetShader(m_Shader_).SetVector4f("colour", glm::vec4(0.6, 0.6, 0.6, 1.0));

	//	transformComponent->setRotation(glm::vec3(0.0f, transformComponent->getRotation().y + 0.001f, 0.0f));


		/*if (m_Meshes_.size() == 1) {
			if (transformComponent != 0) {
				ResourceManager::getInstance()->GetShader(m_Shader_).SetMatrix4("mModel", transformComponent->getModelMatrix());
				glBindVertexArray(*m_Meshes_[0]->getRenderData());
				glEnableVertexAttribArray(0);
				glDrawArrays(GL_TRIANGLES, 0, m_Meshes_[0]->getDrawSize());
			}
		}
		else {*/
			for (t_Mesh_vector_Iterator_ iter = m_Meshes_.begin(); iter != m_Meshes_.end(); ++iter) {
				glm::vec3 p, r, s;
				p = transformComponent->getPosition() + (*iter)->getPosition();
				r = transformComponent->getRotation() + (*iter)->getRotation();
				s = transformComponent->getScale() + (*iter)->getScale();

				glm::mat4 model;
				model = glm::translate(model, p);  
				model = glm::translate(model, glm::vec3(-0.5f * s.x, -0.5f * s.y, -0.5f * s.z)); 
				model = glm::rotate(model, r.x, glm::vec3(1.0f, 0.0f, 0.0f)); 
				model = glm::rotate(model, r.y, glm::vec3(0.0f, 1.0f, 0.0f)); 
				model = glm::rotate(model, r.z, glm::vec3(0.0f, 0.0f, 1.0f)); 
				model = glm::translate(model, glm::vec3(0.5f * s.x, 0.5f * s.y, 0.5f * s.z)); 
				model = glm::scale(model, s);


				ResourceManager::getInstance()->GetShader(m_Shader_).SetMatrix4("mModel", model);
				glBindVertexArray(*(*iter)->getRenderData());
				glEnableVertexAttribArray(0);
				glDrawArrays(GL_TRIANGLES, 0, (*iter)->getDrawSize());
			//}

		}
	}
}


