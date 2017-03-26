#include "loadscene.h"

static const char* ResourcArray[] = {
	"item/cannon",
	"item/caihong",
	"item/Selected_Effects",
	"item/Item-chaojiwuqi",
	"item/caihong",
	"item/Item-GoldStar",
	"fish/FishActor-Marlin",
	"fish/FishActor-Large",
	"fish/FishActor-Shark",
	"fish/FishActor-Mid",
	"fish/FishActor-Small",
};

Scene*loadscene::createScene() {
	auto scene = Scene::create();
	auto layer = loadscene::create();
	scene->addChild(layer);
	return scene;
}

bool loadscene::init() {

	if (!Layer::init()) {
		return false;
	}
	{	//获取 csb中的数据 
		auto m_csbNode = CSLoader::createNode("res/LoadingScene.csb");
		LoadingBar1 = static_cast<LoadingBar*>(m_csbNode->getChildByName("LoadingBar_1"));
		LoadingBar2 = static_cast<LoadingBar*>(m_csbNode->getChildByName("LoadingBar_2"));
		LoadingBar1->setPercent(0.0f);
		LoadingBar2->setPercent(0.0f);
		m_pLabelPercent = static_cast<Text*>(m_csbNode->getChildByName("Text_1"));
		m_pLabelPercent->setString("0%");
		addChild(m_csbNode);
	}

	m_nNumberOfLoadedResource = 0;
	m_nNumberOfResource = sizeof(ResourcArray) / sizeof(ResourcArray[0]);

	return true;
}

void loadscene::onLoadingCallback(Texture2D * texture)
{
	std::string plist = std::string(ResourcArray[m_nNumberOfLoadedResource]) + ".plist";
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plist, texture);
	log("%s", Director::getInstance()->getTextureCache()->getCachedTextureInfo());

	std::string label = StringUtils::format("%d%%", (int)(((float)m_nNumberOfLoadedResource / m_nNumberOfResource) * 100));
	m_pLabelPercent->setString(label);
	LoadingBar1->setPercent(((float)m_nNumberOfLoadedResource / m_nNumberOfResource) * 100);
	LoadingBar2->setPercent(((float)m_nNumberOfLoadedResource / m_nNumberOfResource) * 100);
	
	++m_nNumberOfLoadedResource;
	if (m_nNumberOfLoadedResource == m_nNumberOfResource)
	{
		//std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		scenemanagement::getInstance()->sceneToGame();
	}
}


void loadscene::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	for (int i = 0; i < m_nNumberOfResource; i++) {
		std::string filename = std::string(ResourcArray[i]) + ".png";
		Director::getInstance()->getTextureCache()->addImageAsync(filename, CC_CALLBACK_1(loadscene::onLoadingCallback, this));
	}
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/bgm_camera.mp3");
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/bgm_fire.mp3");
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/bgm_ach.mp3");
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/bgm_change_cannon.mp3");
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/bgm_coin_01.mp3");
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/Bombette.mp3");
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/music_1.mp3");
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/music_2.mp3");
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/music_3.mp3");
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/music_4.mp3");
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/music_5.mp3");
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/music_6.mp3");
}

