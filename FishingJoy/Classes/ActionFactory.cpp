#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif
#include "ActionFactory.h"
ActionFactory*ActionFactory::Instance = nullptr;
ActionFactory * ActionFactory::getInstance()
{
	if (!Instance) {
		Instance = new ActionFactory;
	}
	return Instance;
}
Animate * ActionFactory::GetFishAct_ByTag(int tag, int type)
{
	//Animate*FishAct = nullptr;
	if (type == 0) {
		switch (tag) {
		case 101:return fish_1_Move();break;
		case 102:return fish_2_Move();break;
		case 103:return fish_3_Move();break;
		case 104:return fish_4_Move();break;
		case 105:return fish_5_Move();break;
		case 106:return fish_6_Move();break;
		case 107:return fish_7_Move();break;
		case 108:return fish_8_Move();break;
		case 109:return fish_9_Move();break;
		case 110:return fish_10_Move();break;
		case 111:return fish_11_Move();break;
		case 112:return fish_12_Move();break;
		case 113:return fish_13_Move();break;
		case 114:return fish_14_Move();break;
		case 115:return fish_15_Move();break;
			//case 116:FishAct = fish_16_Move();break;
		}
	}
	else {
		switch (tag) {
		case 101:return fish_1_Die();break;
		case 102:return fish_2_Die();break;
		case 103:return fish_3_Die();break;
		case 104:return fish_4_Die();break;
		case 105:return fish_5_Die();break;
		case 106:return fish_6_Die();break;
		case 107:return fish_7_Die();break;
		case 108:return fish_8_Die();break;
		case 109:return fish_9_Die();break;
		case 110:return fish_10_Die();break;
		case 111:return fish_11_Die();break;
		case 112:return fish_12_Die();break;
		case 113:return fish_13_Die();break;
		case 114:return fish_14_Die();break;
		case 115:return fish_15_Die();break;
		}

		
	}
	return nullptr;
}
Animate*ActionFactory::cannon_1_fire()
{
	auto animatin = Animation::create();
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("cannon/cannon.plist");
	for (int a = 1;a <= 2;a++) {
		std::string temp = StringUtils::format("actor_cannon1_1%d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	// 设置动画帧率
	animatin->setDelayPerUnit(5.0f / 38);
	// 设置动画播放完毕后是否回到第一帧
	animatin->setRestoreOriginalFrame(true);
	// 用动画创建精灵动作
	auto animate = Animate::create(animatin);
	return animate;
}
Animate * ActionFactory::cannon_2_fire()
{
	auto animatin = Animation::create();
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("cannon/cannon.plist");
	for (int a = 1;a <= 2;a++) {
		std::string temp = StringUtils::format("actor_cannon1_2%d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	// 设置动画帧率
	animatin->setDelayPerUnit(5.0f / 38);
	// 设置动画播放完毕后是否回到第一帧
	animatin->setRestoreOriginalFrame(true);
	// 用动画创建精灵动作
	auto animate = Animate::create(animatin);
	return animate;
}
Animate * ActionFactory::cannon_3_fire()
{
	auto animatin = Animation::create();
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("cannon/cannon.plist");
	for (int a = 1;a <= 2;a++) {
		std::string temp = StringUtils::format("actor_cannon1_3%d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	// 设置动画帧率
	animatin->setDelayPerUnit(5.0f / 38);
	// 设置动画播放完毕后是否回到第一帧
	animatin->setRestoreOriginalFrame(true);
	// 用动画创建精灵动作
	auto animate = Animate::create(animatin);
	return animate;
}
Animate * ActionFactory::cannon_4_fire()
{
	auto animatin = Animation::create();
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("cannon/cannon.plist");
	for (int a = 1;a <= 2;a++) {
		std::string temp = StringUtils::format("actor_cannon1_4%d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	// 设置动画帧率
	animatin->setDelayPerUnit(5.0f / 38);
	// 设置动画播放完毕后是否回到第一帧
	animatin->setRestoreOriginalFrame(true);
	// 用动画创建精灵动作
	auto animate = Animate::create(animatin);
	return animate;
}
Animate * ActionFactory::cannon_5_fire()
{
	auto animatin = Animation::create();
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("cannon/cannon.plist");
	for (int a = 1;a <= 2;a++) {
		std::string temp = StringUtils::format("actor_cannon1_5%d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	// 设置动画帧率
	animatin->setDelayPerUnit(5.0f / 38);
	// 设置动画播放完毕后是否回到第一帧
	animatin->setRestoreOriginalFrame(true);
	// 用动画创建精灵动作
	auto animate = Animate::create(animatin);
	return animate;
}
Animate * ActionFactory::cannon_6_fire()
{
	auto animatin = Animation::create();
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("cannon/cannon.plist");
	for (int a = 1;a <= 2;a++) {
		std::string temp = StringUtils::format("actor_cannon1_6%d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	// 设置动画帧率
	animatin->setDelayPerUnit(5.0f / 38);
	// 设置动画播放完毕后是否回到第一帧
	animatin->setRestoreOriginalFrame(true);
	// 用动画创建精灵动作
	auto animate = Animate::create(animatin);
	return animate;
}
Animate * ActionFactory::cannon_7_fire()
{
	auto animatin = Animation::create();
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("cannon/cannon.plist");
	for (int a = 1;a <= 2;a++) {
		std::string temp = StringUtils::format("actor_cannon1_7%d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	// 设置动画帧率
	animatin->setDelayPerUnit(5.0f / 38);
	// 设置动画播放完毕后是否回到第一帧
	animatin->setRestoreOriginalFrame(true);
	// 用动画创建精灵动作
	auto animate = Animate::create(animatin);
	return animate;
}
Animate * ActionFactory::cannon_jiguang_fire()
{
	auto animatin = Animation::create();
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("cannon/cannon.plist");
	for (int a = 1;a <= 2;a++) {
		std::string temp = StringUtils::format("actor_cannon_jiguang_0%d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	// 设置动画帧率
	animatin->setDelayPerUnit(5.0f / 38);
	// 设置动画播放完毕后是否回到第一帧
	animatin->setRestoreOriginalFrame(true);
	// 用动画创建精灵动作
	auto animate = Animate::create(animatin);
	return animate;
}
Animate * ActionFactory::cannon_jiguang_Boom()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 29;a++) {
		std::string temp = StringUtils::format("Effect_swenpon1_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 60);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}
Animate * ActionFactory::BullectBoom1()
{
	auto animatin = Animation::create();
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("fish/FishActor-Marlin.plist");
	for (int a = 1;a <= 7;a++) {
		std::string temp = StringUtils::format("weapon_net_00%d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	// 设置动画帧率
	animatin->setDelayPerUnit(5.0f / 38);
	// 设置动画播放完毕后是否回到第一帧
	animatin->setRestoreOriginalFrame(true);
	// 用动画创建精灵动作
	auto animate = Animate::create(animatin);
	return animate;
}
Animate * ActionFactory::BullectBoom2()
{
	auto animatin = Animation::create();
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("fish/FishActor-Marlin.plist");
	for (int a = 1;a <= 7;a++) {
		std::string temp = StringUtils::format("weapon_snet_00%d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	// 设置动画帧率
	animatin->setDelayPerUnit(5.0f / 38);
	// 设置动画播放完毕后是否回到第一帧
	animatin->setRestoreOriginalFrame(true);
	// 用动画创建精灵动作
	auto animate = Animate::create(animatin);
	return animate;
}
Animate * ActionFactory::caiHong()
{
	auto animatin = Animation::create();
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("fish/FishActor-Marlin.plist");
	for (int a = 1;a <= 5;a++) {
		std::string temp = StringUtils::format("caihong_%d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	// 设置动画帧率
	animatin->setDelayPerUnit(5.0f / 38);
	// 设置动画播放完毕后是否回到第一帧
	animatin->setRestoreOriginalFrame(true);
	// 用动画创建精灵动作
	auto animate = Animate::create(animatin);
	return animate;
}
Animate * ActionFactory::Gold()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 5;a++) {
		std::string temp = StringUtils::format("effect_res_gold2_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}
Animate * ActionFactory::Select()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 8;a++) {
		std::string temp = StringUtils::format("Selected_Effects_%02d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}
Animate * ActionFactory::fish_1_Move()
{
	auto animatin = Animation::create();
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("fish/FishActor-Marlin.plist");
	for (int a = 1;a <= 10;a++) {
		std::string temp = StringUtils::format("move/GrouperFish_actor_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	// 设置动画帧率
	animatin->setDelayPerUnit(5.0f / 38);
	// 设置动画播放完毕后是否回到第一帧
	animatin->setRestoreOriginalFrame(true);
	// 用动画创建精灵动作
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_1_Die()
{
	auto animatin = Animation::create();
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("fish/FishActor-Marlin.plist");
	for (int a = 1;a <= 5;a++) {
		std::string temp = StringUtils::format("GrouperFish_death_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	// 设置动画帧率
	animatin->setDelayPerUnit(5.0f / 38);
	// 设置动画播放完毕后是否回到第一帧
	animatin->setRestoreOriginalFrame(true);
	// 用动画创建精灵动作
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_2_Move()
{
	auto animatin = Animation::create();
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("fish/FishActor-Marlin.plist");
	for (int a = 1;a <= 10;a++) {
		std::string temp = StringUtils::format("move/GMarlinsFish_actor_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	// 设置动画帧率
	animatin->setDelayPerUnit(5.0f / 38);
	// 设置动画播放完毕后是否回到第一帧
	animatin->setRestoreOriginalFrame(true);
	// 用动画创建精灵动作
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_2_Die()
{
	auto animatin = Animation::create();
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("fish/FishActor-Marlin.plist");
	for (int a = 1;a <= 4;a++) {
		std::string temp = StringUtils::format("GMarlinsFish_death_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	// 设置动画帧率
	animatin->setDelayPerUnit(5.0f / 38);
	// 设置动画播放完毕后是否回到第一帧
	animatin->setRestoreOriginalFrame(true);
	// 用动画创建精灵动作
	auto animate = Animate::create(animatin);
	return animate;

}

Animate * ActionFactory::fish_3_Move()
{
	auto animatin = Animation::create();
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("fish/FishActor-Marlin.plist");
	for (int a = 1;a <= 10;a++) {
		std::string temp = StringUtils::format("move/MarlinsFish_actor_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	// 设置动画帧率
	animatin->setDelayPerUnit(5.0f / 38);
	// 设置动画播放完毕后是否回到第一帧
	animatin->setRestoreOriginalFrame(true);
	// 用动画创建精灵动作
	auto animate = Animate::create(animatin);
	return animate;

}

Animate * ActionFactory::fish_3_Die()
{
	auto animatin = Animation::create();
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("fish/FishActor-Marlin.plist");
	for (int a = 1;a <= 4;a++) {
		std::string temp = StringUtils::format("MarlinsFish_death_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	// 设置动画帧率
	animatin->setDelayPerUnit(5.0f / 38);
	// 设置动画播放完毕后是否回到第一帧
	animatin->setRestoreOriginalFrame(true);
	// 用动画创建精灵动作
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_4_Move()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 9;a++) {
		std::string temp = StringUtils::format("move/Chelonian_actor_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_4_Die()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 5;a++) {
		std::string temp = StringUtils::format("Chelonian_death_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_5_Move()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 9;a++) {
		std::string temp = StringUtils::format("move/Ray_actor_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_5_Die()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 5;a++) {
		std::string temp = StringUtils::format("Ray_death_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_6_Move()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 6;a++) {
		std::string temp = StringUtils::format("move/GoldenTrout_actor_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_6_Die()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 5;a++) {
		std::string temp = StringUtils::format("GoldenTrout_death_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_7_Move()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 5;a++) {
		std::string temp = StringUtils::format("move/JadePerch_actor_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_7_Die()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 5;a++) {
		std::string temp = StringUtils::format("JadePerch_death_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_8_Move()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 10;a++) {
		std::string temp = StringUtils::format("move/GShark_actor_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_8_Die()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 3;a++) {
		std::string temp = StringUtils::format("GShark_death_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_9_Move()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 10;a++) {
		std::string temp = StringUtils::format("move/Shark_actor_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_9_Die()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 3;a++) {
		std::string temp = StringUtils::format("Shark_death_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_10_Move()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 10;a++) {
		std::string temp = StringUtils::format("move/Lantern_actor_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(10.0f / 60);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_10_Die()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 5;a++) {
		std::string temp = StringUtils::format("Lantern_death_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_11_Move()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 5;a++) {
		std::string temp = StringUtils::format("move/Croaker_actor_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_11_Die()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 5;a++) {
		std::string temp = StringUtils::format("Croaker_death_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_12_Move()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 4;a++) {
		std::string temp = StringUtils::format("move/SmallFish_actor_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_12_Die()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 5;a++) {
		std::string temp = StringUtils::format("SmallFish_death_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_13_Move()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 9;a++) {
		std::string temp = StringUtils::format("move/Bream_actor_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_13_Die()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 5;a++) {
		std::string temp = StringUtils::format("Bream_death_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_14_Move()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 6;a++) {
		std::string temp = StringUtils::format("move/Amphiprion_actor_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_14_Die()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 5;a++) {
		std::string temp = StringUtils::format("Amphiprion_death_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_15_Move()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 10;a++) {
		std::string temp = StringUtils::format("move/AngelFish_actor_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_15_Die()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 5;a++) {
		std::string temp = StringUtils::format("AngelFish_death_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_16_Move1()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 6;a++) {
		std::string temp = StringUtils::format("move_a/PufferS_actor_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}

Animate * ActionFactory::fish_16_Move2()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 6;a++) {
		std::string temp = StringUtils::format("move_b/PufferB_actor_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
	
}

Animate * ActionFactory::fish_16_Die()
{
	auto animatin = Animation::create();
	for (int a = 1;a <= 3;a++) {
		std::string temp = StringUtils::format("PufferS_death_%03d.png", a);
		animatin->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
	}
	animatin->setDelayPerUnit(5.0f / 38);
	animatin->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animatin);
	return animate;
}
