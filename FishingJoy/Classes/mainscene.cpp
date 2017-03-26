
#include "mainscene.h"
//实现水波效果
#include"WaterEffectSprite.h"
Scene* mainscene::createScene() {
	auto scene = Scene::create();
	auto layer = mainscene::create();
	scene->addChild(layer);
	return scene;
}

bool mainscene::init() {
	if (!Layer::init()) {
		return false;
	}
	auto s = Director::getInstance()->getWinSize();
	auto bg = WaterEffectSprite::create("main/ui_background_normal_sx.jpg");
	bg->setPosition(s.width / 2, s.height / 2);
	addChild(bg);
	
	auto title = Sprite::create("main/main_ui_title_cn.png");
	title->setPosition(s.width / 2, s.height / 2 + 100);
	addChild(title);

	auto startButton = MenuItemImage::create("main/start1.png", "main/start2.png", this, menu_selector(mainscene::menuHome));
	auto menu = Menu::create(startButton, nullptr);
	menu->setPosition(s.width / 2, s.height / 2 - 150);
	addChild(menu);
	
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/music_1.mp3", true);
	
	return true;
}
void mainscene::menuHome(Ref *sender) {
	scenemanagement::getInstance()->sceneToLoad();
}
