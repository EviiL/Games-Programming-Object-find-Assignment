#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <iostream>
#include "Object.h"

class Object;

class Component {
	private:
		
	protected:
		Object * m_ObjectParent_;
	public:

		std::string M_ComponentName;


		virtual void Update(double dt) = 0;
		virtual void LateUpdate(double dt) = 0;
		
		virtual void Destroy() = 0;
		virtual void Start() = 0;

};



#endif