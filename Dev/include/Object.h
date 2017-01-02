#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <vector>
#include "Components\Component.h"
#include "ComponentVectorWrapper.h"

class Component;

class Object {

public:

	Object(const char* pName);
	~Object() {

	}

	const char* M_Name_;

	void registerComponent(Component * pComponent);
	void removeComponent(Component * pComponent);

	void UpdateComponents(double dt);
	void LateUpdateComponents();

	ComponentVectorWrapper::t_Components_Vector_& getComponents() {
		return m_Components_;
	}

	bool checkComponentExists(std::string pName);
	
	template<typename T>
	T* GetComponentByType() {
		for (ComponentVectorWrapper::t_Component_Iter iter = m_Components_.begin(); iter != m_Components_.end(); ++iter)
			if (*iter != nullptr)
				if (T* type = dynamic_cast<T*>(*iter))
					return type;
		return nullptr;
	}

	template<typename T>
	bool CheckComponentTypeExists() {
		for (ComponentVectorWrapper::t_Component_Iter iter = m_Components_.begin(); iter != m_Components_.end(); ++iter)
			if (*iter != nullptr)
				if (T* type = dynamic_cast<T*>(*iter))
					return true;
		return false;
	}

private:


	


	ComponentVectorWrapper::t_Components_Vector_ m_Components_;

};

#endif