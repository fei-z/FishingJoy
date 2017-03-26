#pragma once

#include"cocos2d.h"
USING_NS_CC;

class WaterEffectSprite :public Sprite
{
public:
	WaterEffectSprite();
	~WaterEffectSprite();
public:
	static WaterEffectSprite* create(const char *pszFileName);
public:
	bool initWithTexture(Texture2D* texture, const Rect&  rect);
	void initGLProgram();
};
