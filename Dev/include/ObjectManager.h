#ifndef _ENTITY_MANAGER_H_
#define _ENTITY_MANAGER_H_

#include <vector>
#include <iostream>

#include "Object.h"


//One EntityManager Per scene but because there is only one scene here, this is irrelevant.
class ObjectManager {

public:
	ObjectManager();
	~ObjectManager() {

	}

	std::vector<Object *> getObjects() {
		return m_Objects_;
	}
	std::vector<Object *> getAllObjectsWithComponent(std::string pName);

private:
	std::vector<Object *> m_Objects_;
};



#endif