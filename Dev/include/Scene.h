#ifndef _SCENE_H_
#define _SCENE_H_

#include <vector>

#include "Object.h"
#include "ObjectVectorWrapper.h"
#include "ComponentVectorWrapper.h"

class Scene {
	

public:
	Scene();
	Scene(std::string pName);
	~Scene() {

	}

	int AddObject(Object pObject);
	void RemoveObject(Object * pObject);

	//Update the scene's contents.
	void Update(double dt);

	//Start the scene and its contents.
	void Start();

	//Destroy the scene and its contents.
	void Destroy();

	std::string getName() {
		return m_Name_;
	}

	ObjectVectorWrapper::t_Object_Vector_& getObjects() {
		return m_SceneObjects_;
	}
	bool M_bIsDirty = true;

private:
	
	ObjectVectorWrapper::t_Object_Vector_ m_SceneObjects_;
	


	std::string m_Name_;



};


#endif