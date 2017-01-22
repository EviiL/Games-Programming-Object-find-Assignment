#include "Components\PlayerKeyboardControlComponent.h"
#include "InputHandler.h"

#include <GLFW\glfw3.h>



PlayerKeyboardControlComponent::PlayerKeyboardControlComponent(GameObject * pParent) {
	m_GameObjectParent_ = pParent;

	M_ComponentName = "PLAYER_KEYBOARD_CONTROL_COMPONENT";
	m_ParentTransform_ = m_GameObjectParent_->GetComponentByType<TransformComponent>();
}

void PlayerKeyboardControlComponent::Update(double dt) {
	if (m_Enabled_) {

		//For the moment, raise the current GameObject.
		if (InputHandler::isKeyDown(GLFW_KEY_SPACE)) {
			m_ParentTransform_->setPosition(glm::vec3(m_ParentTransform_->getPosition().x, m_ParentTransform_->getPosition().y + 0.1, m_ParentTransform_->getPosition().z));
		}

		if (InputHandler::isKeyDown(GLFW_KEY_LEFT_SHIFT)) {
			m_ParentTransform_->setPosition(glm::vec3(m_ParentTransform_->getPosition().x, m_ParentTransform_->getPosition().y - 0.1, m_ParentTransform_->getPosition().z));
		}

		if (InputHandler::isKeyDown(GLFW_KEY_W)) {
			float x, z;
			x = m_ParentTransform_->getPosition().x + m_ParentTransform_->getDirection().x * float(dt * 0.05f);
			z = m_ParentTransform_->getPosition().z + m_ParentTransform_->getDirection().z * float(dt * 0.05f);
			glm::vec3 temp = glm::vec3(x, m_ParentTransform_->getPosition().y, z);

			m_ParentTransform_->setPosition(temp);
		}

		if (InputHandler::isKeyDown(GLFW_KEY_S)) {
			float x, z;

			x = m_ParentTransform_->getPosition().x - m_ParentTransform_->getDirection().x * float(dt * 0.05f);
			z = m_ParentTransform_->getPosition().z - m_ParentTransform_->getDirection().z * float(dt * 0.05f);

			glm::vec3 temp = glm::vec3(x, m_ParentTransform_->getPosition().y, z);			
			m_ParentTransform_->setPosition(temp);
		}

		if (InputHandler::isKeyDown(GLFW_KEY_D)) {
			float x, z;

			x = m_ParentTransform_->getPosition().x - m_ParentTransform_->getRight().x * float(dt * 0.05f);
			z = m_ParentTransform_->getPosition().z - m_ParentTransform_->getRight().z * float(dt * 0.05f);

			glm::vec3 temp = glm::vec3(x, m_ParentTransform_->getPosition().y, z);
			m_ParentTransform_->setPosition(temp);
		}

		if (InputHandler::isKeyDown(GLFW_KEY_A)) {
			float x, z;

			x = m_ParentTransform_->getPosition().x + m_ParentTransform_->getRight().x * float(dt * 0.05f);
			z = m_ParentTransform_->getPosition().z + m_ParentTransform_->getRight().z * float(dt * 0.05f);

			glm::vec3 temp = glm::vec3(x, m_ParentTransform_->getPosition().y, z);		
			m_ParentTransform_->setPosition(temp);
		}


	}
}
void PlayerKeyboardControlComponent::LateUpdate(double dt) {

}
void PlayerKeyboardControlComponent::Destroy() {

}
void PlayerKeyboardControlComponent::Start() {

}