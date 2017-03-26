#ifndef gamelogo_hpp
#define gamelogo_hpp

#include"Header.h"
class gamelogo :public cocos2d::Layer
{
	float ShowTime;
	float NowTime;
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(gamelogo);

	virtual void update(float dt);

};



#endif /* gamelogo_hpp */
