#include "Scene.h"
#include "Components\RenderComponent.h"
#include "Rendering\MeshFactory.h"


#include <memory>


Scene::Scene() {
	
}

Scene::Scene(std::string pName) {
	m_Name_ = pName;
}

int Scene::AddObject(Object pObject) {
	m_SceneObjects_.push_back(pObject);
	M_bIsDirty = true;
	return m_SceneObjects_.size() - 1;
}

void Scene::RemoveObject(Object * pObject) {
	M_bIsDirty = true;

}

void Scene::Update(double dt){

	//Standard Update.
	for (ObjectVectorWrapper::t_Object_Vector_Iterator_ iter = m_SceneObjects_.begin(); iter != m_SceneObjects_.end(); ++iter) {
		(*iter).UpdateComponents(dt);
	}


	//Late update.
	for (ObjectVectorWrapper::t_Object_Vector_Iterator_ iter = m_SceneObjects_.begin(); iter != m_SceneObjects_.end(); ++iter) {
		(*iter).LateUpdateComponents();

	}
}


void Scene::Start() {

	//Start the Components within the Scene.

	for (ObjectVectorWrapper::t_Object_Vector_Iterator_ iter = m_SceneObjects_.begin(); iter != m_SceneObjects_.end(); ++iter) {
		for (ComponentVectorWrapper::t_Component_Iter iter2 = (*iter).getComponents().begin(); iter2 != (*iter).getComponents().end(); ++iter2) {
			(*iter2)->Start();
		}
	}
}


void Scene::Destroy() {
	//Destroy the components.
	for (ObjectVectorWrapper::t_Object_Vector_Iterator_ iter = m_SceneObjects_.begin(); iter != m_SceneObjects_.end(); ++iter) {
		for (ComponentVectorWrapper::t_Component_Iter iter2 = (*iter).getComponents().begin(); iter2 != (*iter).getComponents().end(); ++iter2) {
			(*iter2)->Destroy();
		}
	}


	//Clear the objects vector.
	m_SceneObjects_.clear();
}