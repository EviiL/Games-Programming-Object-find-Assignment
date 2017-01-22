#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_


#include "Scene.h"
#include <iostream>
#include "Rendering\Renderer.h"
#include "Rendering\GUI\GUIRenderer.h"

#include "Rendering\ResourceManager.h"
#include "Components\TransformComponent.h"
#include "Components\RenderComponent.h"
#include "Components\PlayerKeyboardControlComponent.h"
#include "Components\FirstPersonCameraComponent.h"
#include "Components\GUI\CanvasComponent.h"


#include "Rendering\GUI\CanvasRect.h"


#include "Rendering\MeshFactory.h"

class SceneManager {

private:

	Scene * m_CurrentScene_;
	Scene * m_Unswitched_;

	bool m_switch_;

public:

	SceneManager();
	~SceneManager() {

	}

	bool LoadScene(std::string pPath);
	void switchScene();

	void DeleteScene();

	Scene * getCurrentScene() {
		return m_CurrentScene_;
	}

	void UpdateRenderers(Renderer * pRenderer, GUIRenderer * pGUIRenderer);

	bool NewSceneReady() {
		return m_switch_;
	}

};


#endif