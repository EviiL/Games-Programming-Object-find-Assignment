#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include "Scene.h"
#include <iostream>
#include "Rendering\Renderer.h"

#include "Rendering\ResourceManager.h"
#include "Components\TransformComponent.h"
#include "Components\RenderComponent.h"
#include "Components\PlayerKeyboardControlComponent.h"
#include "Rendering\MeshFactory.h"

class SceneManager {

private:

	Scene * m_CurrentScene_;

public:

	SceneManager();
	~SceneManager() {

	}

	bool LoadScene(std::string pPath);

	void DeleteScene();

	Scene * getCurrentScene() {
		return m_CurrentScene_;
	}

	void UpdateRenderer(Renderer * pRenderer);

};


#endif