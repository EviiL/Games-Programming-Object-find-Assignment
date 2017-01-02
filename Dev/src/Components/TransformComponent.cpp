
#include "Components\TransformComponent.h"

TransformComponent::TransformComponent(Object * pParent) {
	m_ObjectParent_ = pParent;

	M_ComponentName = "TRANSFORM_COMPONENT";

}

void TransformComponent::Update(double dt) {

	//Should probably be moved to the late update, but i'll do that later, cba right now.
	
	if (m_bDirty_) {
		m_Model_ = glm::translate(m_Model_, m_Position_);  // First translate (transformations are: scale happens first, then rotation and then final translation happens; reversed order)

		m_Model_ = glm::translate(m_Model_, glm::vec3(0.5f * m_Scale_.x, 0.5f * m_Scale_.y, 0.5f * m_Scale_.z)); // Move origin of rotation to center of quad
		m_Model_ = glm::rotate(m_Model_, m_Rotation_.x, glm::vec3(1.0f, 0.0f, 0.0f)); // Then rotate X
		m_Model_ = glm::rotate(m_Model_, m_Rotation_.y, glm::vec3(0.0f, 1.0f, 0.0f)); // Then rotate Y
		m_Model_ = glm::rotate(m_Model_, m_Rotation_.z, glm::vec3(0.0f, 0.0f, 1.0f)); // Then rotate Z
		m_Model_ = glm::translate(m_Model_, glm::vec3(-0.5f * m_Scale_.x, -0.5f * m_Scale_.y, -0.5f * m_Scale_.z)); // Move origin back

		m_Model_ = glm::scale(m_Model_, m_Scale_); // Last scale
		m_bDirty_ = false;
	}

}
void TransformComponent::LateUpdate(double dt) {

}

void TransformComponent::Destroy() {
	delete this;
}

void TransformComponent::Start() {
	m_bDirty_ = true;
}


