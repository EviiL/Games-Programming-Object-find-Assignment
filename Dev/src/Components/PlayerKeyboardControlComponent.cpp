#include "Components\PlayerKeyboardControlComponent.h"
#include "KeyboardHandler.h"

#include <GLFW\glfw3.h>



PlayerKeyboardControlComponent::PlayerKeyboardControlComponent(Object * pParent) {
	m_ObjectParent_ = pParent;

	M_ComponentName = "PLAYER_KEYBOARD_CONTROL_COMPONENT";
	m_ParentTransform_ = m_ObjectParent_->GetComponentByType<TransformComponent>();
}

void PlayerKeyboardControlComponent::Update(double dt) {
	if (m_Enabled_) {

		//For the moment, raise the current object.
		if (KeyboardHandler::isKeyDown(GLFW_KEY_W)) {
			m_ParentTransform_->setPosition(glm::vec3(m_ParentTransform_->getPosition().x, m_ParentTransform_->getPosition().y + 0.01, m_ParentTransform_->getPosition().z));
		}
	}
}
void PlayerKeyboardControlComponent::LateUpdate(double dt) {

}
void PlayerKeyboardControlComponent::Destroy() {

}
void PlayerKeyboardControlComponent::Start() {

}