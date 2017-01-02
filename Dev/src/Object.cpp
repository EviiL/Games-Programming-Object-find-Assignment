#include "Object.h"
#include "Components\TransformComponent.h"


Object::Object(const char* pName) {
	M_Name_ = pName;
	registerComponent(new TransformComponent(this)); //Every object has a transform component, can be removed later as its easier to assume it exists.
}

bool Object::checkComponentExists(std::string pName) {

	for (int i = m_Components_.size(); i--;)
		if (m_Components_[i]->M_ComponentName == pName)
			return true;
	return false;

}


void Object::registerComponent(Component * pComponent) {
	m_Components_.push_back(pComponent);
}
void Object::removeComponent(Component * pComponent) {
	//TODO add removal of components.
}

void Object::UpdateComponents(double dt) {
	for (ComponentVectorWrapper::t_Component_Iter iter = m_Components_.begin(); iter != m_Components_.end(); ++iter)
		(*iter)->Update(dt);
}

void Object::LateUpdateComponents() {
	for (ComponentVectorWrapper::t_Component_Iter iter = m_Components_.begin(); iter != m_Components_.end(); ++iter)
		(*iter)->LateUpdate(0.0);
}




