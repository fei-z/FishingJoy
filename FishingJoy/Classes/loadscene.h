#ifndef loadscene_hpp
#define loadscene_hpp
#include"Header.h"
#include "SceneManagement.h"

class loadscene :public Layer
{
private:
	int m_nNumberOfResource; //加载资源总数
	int m_nNumberOfLoadedResource; //已载入的资源数
	Text*m_pLabelPercent;//百分比标签
	LoadingBar *LoadingBar1;//进度条一
	LoadingBar *LoadingBar2;//进度条二
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(loadscene);
	void onLoadingCallback(Texture2D* texture);
	virtual void onEnterTransitionDidFinish();
};

#endif /* loadscene_hpp */
