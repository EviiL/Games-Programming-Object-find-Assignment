#include "SceneManager.h"


SceneManager::SceneManager() {

}

bool SceneManager::LoadScene(std::string pPath) {
	//Process and create the scene here.

	//Load the name from the file obviously.
	m_CurrentScene_ = new Scene("Main");
	Object Cube = Object("Cube");
	int index = m_CurrentScene_->AddObject(Cube);

	RenderComponent * renderC = new RenderComponent(&m_CurrentScene_->getObjects()[index], "default");
	PlayerKeyboardControlComponent * keyComp = new PlayerKeyboardControlComponent(&m_CurrentScene_->getObjects()[index]);
	MeshFactory factory;

	renderC->AttachMesh(factory.create("Models/cube.obj", glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)));
	renderC->AttachMesh(factory.create("Models/cube.obj", glm::vec3(-5.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 2.0f)));

	m_CurrentScene_->getObjects()[index].registerComponent(renderC);
	m_CurrentScene_->getObjects()[index].registerComponent(keyComp);

	return true;
}

void SceneManager::DeleteScene() {
	//Proof of concept, Never actually fucking use this thing.
	delete m_CurrentScene_;
}

void SceneManager::UpdateRenderer(Renderer * pRenderer) {
	pRenderer->setScene(m_CurrentScene_);
}
