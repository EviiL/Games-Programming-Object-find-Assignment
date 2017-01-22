#ifndef _GameObject_H_
#define _GameObject_H_

#include <memory>	
#include <vector>
#include "Components\Component.h"
#include "ComponentVectorWrapper.h"
#include "Exceptions\ComponentMissingException.h"

class Component;

class GameObject {

public:

	GameObject(const char* pName);
	~GameObject() {

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


	void updateParents() {
		/*for (int i = m_Components_.size(); i--;) {
			m_Components_[i]->setParent(this);
		}*/
	}
	
	template<typename T>
	T* GetComponentByType() {
		try {
			for (ComponentVectorWrapper::t_Component_Iter iter = m_Components_.begin(); iter != m_Components_.end(); ++iter)
				if (*iter != nullptr)
					if (T* type = dynamic_cast<T*>(*iter))
						return type;
			throw ComponentMissingException();
		}
		catch (ComponentMissingException& e) {
			std::cout << e.what() << std::endl;
			__debugbreak();
		}
	}

	template<typename T>
	bool CheckComponentTypeExists() {
		if(m_Components_.size() > 0)
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