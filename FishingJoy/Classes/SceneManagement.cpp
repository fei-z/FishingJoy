#include "SceneManagement.h"

scenemanagement*scenemanagement::Instance = nullptr;
Scene*scenemanagement::Logo_scene = nullptr;
Scene*scenemanagement::Main_scene = nullptr;
Scene*scenemanagement::Load_scene = nullptr;
Scene*scenemanagement::Game_scene = nullptr;
scenemanagement::scenemanagement()
{
	/*Logo_scene = gamelogo::createScene();
	Main_scene = mainscene::createScene();
	Load_scene = loadscene::createScene();
	Game_scene = gamescene::createScene();*/
}

scenemanagement::~scenemanagement()
{
}

scenemanagement*scenemanagement::getInstance() {
	if (!Instance)
		Instance = new scenemanagement;
	return Instance;
}

void scenemanagement::sceneToLogo() {
	Logo_scene = gamelogo::createScene();
	Director::getInstance()->runWithScene(Logo_scene);
}

void scenemanagement::sceneToMain() {
	Main_scene = mainscene::createScene();
	TransitionScene* ccts = CCTransitionFade::create(1.0f, Main_scene);
	Director::getInstance()->replaceScene(ccts);
}
void scenemanagement::sceneToLoad() {
	Load_scene = loadscene::createScene();
	TransitionScene* ccts = TransitionFadeTR::create(1.0f, Load_scene);
	Director::getInstance()->replaceScene(ccts);
}
void scenemanagement::sceneToGame() {
	Game_scene = gamescene::createScene();
	TransitionScene* ccts = CCTransitionJumpZoom::create(1.f, Game_scene);
	Director::getInstance()->replaceScene(ccts);
	//__FUNCTION__;
	
}

