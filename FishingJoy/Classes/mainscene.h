#ifndef mainscene_hpp
#define mainscene_hpp

#include"Header.h"
#include"SceneManagement.h"
class mainscene :public Layer
{


public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuHome(Ref *sender);

	CREATE_FUNC(mainscene);
};

#endif /* mainscene_hpp */
