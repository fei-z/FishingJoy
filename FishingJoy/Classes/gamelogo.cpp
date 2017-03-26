
#include "gamelogo.h"
#include"Scenemanagement.h"

Scene* gamelogo::createScene() {
	auto scene = Scene::create();
	auto layer = gamelogo::create();
	scene->addChild(layer);
	return scene;
}

bool gamelogo::init() {
	if (!Layer::init()) {
		return false;
	}
	ShowTime = 3.f;
	NowTime = 0.f;
	auto s = Director::getInstance()->getWinSize();
	auto logoimg = Sprite::create("logo/Default-Landscape_sx.jpg");
	logoimg->setPosition(s.width / 2, s.height / 2);
	addChild(logoimg);

	scheduleOnce(schedule_selector(gamelogo::update), 3.f);
	return true;
};

void gamelogo::update(float dt) {
	scenemanagement::getInstance()->sceneToMain();
}


