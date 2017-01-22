#ifndef _PLAYER_KEYBOARD_CONTROL_COMPONENT_H_
#define _PLAYER_KEYBOARD_CONTROL_COMPONENT_H_

#include "TransformComponent.h"
#include "InputComponent.h"
#include "GameObject.h"

class PlayerKeyboardControlComponent : public InputComponent {
private:
	bool m_Enabled_ = true;
	TransformComponent * m_ParentTransform_;

public:
	PlayerKeyboardControlComponent(GameObject * pParent);

	virtual void Update(double dt);
	virtual void LateUpdate(double dt);

	virtual void Destroy();
	virtual void Start();

	bool isEnabled() {
		return m_Enabled_;
	}

	void toggleEnabled(bool pToggle) {
		m_Enabled_ = pToggle;
	}
};


#endif