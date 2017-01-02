#include "ObjectManager.h"


ObjectManager::ObjectManager() {

}


std::vector<Object *> ObjectManager::getAllObjectsWithComponent(std::string pName) {
	std::vector<Object *> temp = std::vector<Object *>();
	for (int i = m_Objects_.size(); i--;) 
		if (m_Objects_[i]->checkComponentExists(pName))
			temp.push_back(m_Objects_[i]);
	return temp;
}