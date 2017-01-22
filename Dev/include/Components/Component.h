#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>
#include <iostream>
#include "GameObject.h"

class GameObject;

class Component {
	private:
		
	protected:
		GameObject * m_GameObjectParent_;
	public:

		std::string M_ComponentName;


		virtual void Update(double dt) = 0;
		virtual void LateUpdate(double dt) = 0;
		
		virtual void Destroy() = 0;
		virtual void Start() = 0;

		void setParent(GameObject * pParent) {
			m_GameObjectParent_ = pParent;
		}

};



#endif