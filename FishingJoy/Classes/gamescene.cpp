#include "gamescene.h"
#include"SceneManagement.h"
#include "ActionFactory.h"

Scene*gamescene::createScene() {
	auto scene = Scene::create();
	auto layer = gamescene::create();
	scene->addChild(layer);
	return scene;
}
void gamescene::buttonJiaClickCallback(cocos2d::Ref * pSender)
{
	//当前武器是炮才更换,激光就略掉
	if (now_Arms == is_Pao) {
		PaoChangeSucced = false;
		now_PaoNum++;
		if (now_PaoNum > all_PaoNum)
		{
			now_PaoNum = 0;
		}
		Now_pao->runAction(CCSequence::create(
			CCScaleTo::create(0.5f, 0.3f),
			CCCallFunc::create(this, callfunc_selector(gamescene::ScaleCallback)),
			NULL));
		int sundID = SimpleAudioEngine::sharedEngine()->playEffect("music/bgm_change_cannon.mp3");
	}
	

}
void gamescene::buttonJianClickCallback(cocos2d::Ref * pSender)
{
	if (now_Arms == is_Pao) {
		PaoChangeSucced = false;

		now_PaoNum--;
		if (now_PaoNum < 0)
		{
			now_PaoNum = 6;
		}
		Now_pao->runAction(CCSequence::create(
			CCScaleTo::create(0.5f, 0.3f),
			CCCallFunc::create(this, callfunc_selector(gamescene::ScaleCallback)),
			NULL));
		int sundID = SimpleAudioEngine::sharedEngine()->playEffect("music/bgm_change_cannon.mp3");
	}
	
}
void gamescene::CameraButtonCallback(Ref * pSender)
{
	int m_soundID = SimpleAudioEngine::sharedEngine()->playEffect("music/bgm_camera.mp3");
}
void gamescene::ChangeBackMusicCallback(Ref * pSender)
{
	static int MusicID = 0;
	switch (MusicID)
	{
	case 0:SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/music_1.mp3", true);break;
	case 1:SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/music_2.mp3", true);break;
	case 2:SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/music_3.mp3", true);break;
	case 3:SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/music_4.mp3", true);break;
	case 4:SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/music_5.mp3", true);break;
	case 5:SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/music_6.mp3", true);break;
	default:
		break;
	}
	if (++MusicID > 5)
		MusicID = 0;

}
void gamescene::PauseMenuCallback(Ref * pSender)
{
	auto s = Director::getInstance()->getWinSize();
	//PauseNode->setVisible(true);
	PauseNode->setZOrder(5);
	PauseNode->runAction(CCSequence::create(
		MoveTo::create(0.5f, Vec2(s.width / 2, s.height / 2)),
		JumpTo::create(0.5,Vec2(s.width/2,s.height/2),20,1),
		NULL));
	unscheduleAllSelectors();
}
void gamescene::ContinueGameCallback(Ref * pSender)
{
	auto s = Director::getInstance()->getWinSize();
	PauseNode->setZOrder(5);
	PauseNode->runAction(CCSequence::create(
		JumpTo::create(0.5, Vec2(s.width / 2, s.height / 2), 20, 1), 
		MoveTo::create(0.5f, Vec2(s.width / 2, 1500)),
		NULL));
	schedule(schedule_selector(gamescene::FishFactory), 1.f);//造鱼工厂
	schedule(schedule_selector(gamescene::collision), 0.1f);//用于处理子弹与鱼碰撞的逻辑
	schedule(schedule_selector(gamescene::update));//其他需要实时更新的逻辑
}
void gamescene::sceneTomainCallback(Ref * pSender)
{
	scenemanagement::getInstance()->sceneToMain();
}
void gamescene::jiguangPaoCallback(Ref * pSender)
{
	if (now_Arms != is_Jiguang) {
		now_Arms = is_Jiguang;
		auto button = (Button*)pSender;
		getChildByName("Select")->setPosition(button->getPosition());
		//这里还需要写切换激光炮的逻辑
		Now_pao->runAction(CCSequence::create(
			CCScaleTo::create(0.5f, 0.3f),
			CCCallFunc::create(this, callfunc_selector(gamescene::ScaleCallback)),
			NULL));
		int sundID = SimpleAudioEngine::sharedEngine()->playEffect("music/bgm_change_cannon.mp3");
	}
	
}
void gamescene::putongPaoCallback(Ref * pSender)
{
	if (now_Arms != is_Pao) {
		now_Arms = is_Pao;
		auto button = (Button*)pSender;
		getChildByName("Select")->setPosition(button->getPosition());
		//这里还需要写切换的逻辑
		Now_pao->runAction(CCSequence::create(
			CCScaleTo::create(0.5f, 0.3f),
			CCCallFunc::create(this, callfunc_selector(gamescene::ScaleCallback)),
			NULL));
		int sundID = SimpleAudioEngine::sharedEngine()->playEffect("music/bgm_change_cannon.mp3");
	}
	
}
bool gamescene::init() {
	if (!Layer::init()) {
		return false;
	}
	
	auto s = Director::getInstance()->getWinSize();
	{	//其他 参数设置
		//开启触摸事件
		setTouchEnabled(true);
		//设置为单点触摸  
		setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

		GameTime = 0.f;
		PaoChangeSucced = true;
		JiguangEnd = true;
		FishNode = Node::create();
		addChild(FishNode, 2);
		Now_Round = Round_one;//造鱼用
		now_Arms = is_Pao;//当前使用的武器

		auto Select = Sprite::create();
		Select->setPosition(810, 30);
		Select->setScale(1.3f);
		addChild(Select,10,"Select");
		Select->runAction(RepeatForever::create(ACT_FTY->Select()));

		//播放背景音乐
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/music_2.mp3", true);
	}
	{	//csb资源


		auto m_csbNode = CSLoader::createNode("res/GameScene.csb");
		addChild(m_csbNode);
		//背景层
		BackScene = static_cast<Sprite*>(m_csbNode->getChildByName("backScene"));
		BackScene->setZOrder(-1);//最底层
		
		//正上角旋转的精灵
		auto angle_img = static_cast<Sprite*>(m_csbNode->getChildByName("Angle_sprite"));
		angle_img->runAction(RepeatForever::create(CCRotateBy::create(1.f, 50)));

		//截屏按扭
		auto  CameraButton= static_cast<Button*>(m_csbNode->getChildByName("Camera"));
		CameraButton->addClickEventListener(CC_CALLBACK_1(gamescene::CameraButtonCallback, this));
		
		//音乐更换按钮
		auto  MusicButton = static_cast<Button*>(m_csbNode->getChildByName("Music"));
		MusicButton->addClickEventListener(CC_CALLBACK_1(gamescene::ChangeBackMusicCallback, this));
		
		//初始金币数
		money = static_cast<TextAtlas*>(m_csbNode->getChildByName("MoneyText"));
		m_I_bufferNumber = m_I_number = 999999;
		std::string s_Money = StringUtils::format("%07d", m_I_number);
		money->setString(s_Money);

		//炮台加号
		auto button_jia = static_cast<Button*>(m_csbNode->getChildByName("Button_3"));
		button_jia->addClickEventListener(CC_CALLBACK_1(gamescene::buttonJiaClickCallback, this));
		//炮台减号
		auto button_jian = static_cast<Button*>(m_csbNode->getChildByName("Button_4"));
		button_jian->addClickEventListener(CC_CALLBACK_1(gamescene::buttonJianClickCallback, this));
		//激光炮按钮
		auto jiguang = static_cast<Button*>(m_csbNode->getChildByName("Button_6"));
		jiguang->addClickEventListener(CC_CALLBACK_1(gamescene::jiguangPaoCallback, this));
		//普通 炮按钮
		auto PutongPao = static_cast<Button*>(m_csbNode->getChildByName("Button_5"));
		PutongPao->addClickEventListener(CC_CALLBACK_1(gamescene::putongPaoCallback, this));
		//暂停节点-游戏设置
		auto button_Pause = static_cast<Button*>(m_csbNode->getChildByName("Button_13"));
		button_Pause->addClickEventListener(CC_CALLBACK_1(gamescene::PauseMenuCallback, this));
		PauseNode= static_cast<Node*>(m_csbNode->getChildByName("Node_1"));
		PauseNode->setPosition(s.width / 2, 1500);
		PauseNode->setZOrder(999);
		auto continueGame = (Button*)PauseNode->getChildByName("Button_10");
		continueGame->addClickEventListener(CC_CALLBACK_1(gamescene::ContinueGameCallback, this));
		auto sceneTomain = (Button*)PauseNode->getChildByName("Button_12");
		//sceneTomain->addClickEventListener(CC_CALLBACK_1(gamescene::sceneTomainCallback, this));
		
		//金币充值节点
		rechargeNode = static_cast<Node*>(m_csbNode->getChildByName("Node_2"));
		rechargeNode->setPosition(s.width / 2, 1500);


	}


	{	//炮台参数
		last_PaoNum = now_PaoNum = 0;
		all_PaoNum = 6;
		angle = 0.f;
		//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("cannon/cannon.plist");
		for (int paoNum = 1;paoNum <= 7;paoNum++)
		{
			std::string temp = StringUtils::format("actor_cannon1_%d1.png", paoNum);
			pao[paoNum - 1] = Sprite::createWithSpriteFrame(
				SpriteFrameCache::getInstance()->getSpriteFrameByName(temp));
			pao[paoNum - 1]->setPosition(s.width / 2, 50);
			pao[paoNum - 1]->setAnchorPoint(Vec2(0.5f, 0.5f));
			pao[paoNum - 1]->setVisible(false);
			//pao[paoNum - 1]->setRotation(angle);
			addChild(pao[paoNum - 1], 3);
		}
		
		Now_pao = pao[now_PaoNum];
		angle = Now_pao->getRotation();
		pao[now_PaoNum]->setVisible(true);
		
		JiguangPao= Sprite::createWithSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName("actor_cannon_jiguang_01.png"));
		JiguangPao->setPosition(s.width / 2, 50);
		JiguangPao->setVisible(false);
		addChild(JiguangPao);
	}


	schedule(schedule_selector(gamescene::FishFactory), 1.f);//造鱼工厂
	schedule(schedule_selector(gamescene::collision), 0.1f);//用于处理子弹与鱼碰撞的逻辑
	
	schedule(schedule_selector(gamescene::update));//其他需要实时更新的逻辑

	return true;
}

void gamescene::update(float dt)
{

	if (m_I_number > 0)
	{
		if (m_I_bufferNumber != m_I_number)//金币数值 与缓冲数值不同时更新
		{
			//金币增加的情况
			if (m_I_bufferNumber > m_I_number) {
				m_I_number++;
			}
			//金币减少的情况
			else if (m_I_bufferNumber < m_I_number) {
				m_I_number--;
			}
			std::string s_Money = StringUtils::format("%07d", m_I_number);
			money->setString(s_Money);
		}

	}
	else {
		//没金币了
	}
}

bool gamescene::onTouchBegan(Touch * touch, Event * event)
{

	if (!PaoChangeSucced || !JiguangEnd&&now_Arms == is_Jiguang)
		return false;//炮台未切换完成这里不能执行 上一发激光未完成也不能执行这里
	if(now_Arms==is_Jiguang)
		JiguangEnd = false;

	Vec2 touchPoint = touch->getLocation();
	Vec2 paoPoint = Now_pao->getPosition();

	m_TouchPoint = touchPoint;//记录点击位置

	{	//鼠标点击时与炮之间的角度
		double cb_1 = abs(touchPoint.y - paoPoint.y);
		double ab_1 = abs(touchPoint.x - paoPoint.x);
		double ac_1 = sqrtf(cb_1*cb_1 + ab_1*ab_1);
		double acb_1 = (ac_1*ac_1 + ab_1*ab_1 - cb_1*cb_1) / (2 * ab_1*ac_1);
		angle = CC_RADIANS_TO_DEGREES(acb_1);//acb / 3.141592653f * 180;
		//57.2748413
		if (angle >= 45.f) {
			double bc_2 = abs(touchPoint.x - paoPoint.x);
			double ba_2 = abs(touchPoint.y - paoPoint.y);
			double ac_2 = sqrtf(bc_2*bc_2 + ba_2*ba_2);
			double acb_2 = (ba_2*ba_2 + ac_2*ac_2 - bc_2*bc_2) / (2 * ba_2*ac_2);
			angle = 90-CC_RADIANS_TO_DEGREES(acb_2);//acb / 3.141592653f * 180;
		}
		if (touchPoint.x < paoPoint.x) {
			angle = -angle;
		}
		float angleTime = abs(angle - Now_pao->getRotation()) / 300;//90-0/100,数值越高角度越灵敏
		
		
		
		//设置炮台旋转到鼠标点击角度，后触发fire回调
		Now_pao->runAction(CCSequence::create(
			CCRotateTo::create(angleTime, angle),
			CCCallFunc::create(this, callfunc_selector(gamescene::BulletFireCallback)),
			NULL));

	
	}
	return true;
}
void gamescene::onTouchMoved(Touch * touch, Event * event)
{
}

void gamescene::onTouchEnded(Touch * touch, Event * event)
{
}


void gamescene::collision(float dt)
{
	Vector<cocos2d::Node*>Children = FishNode->getChildren();//获取当前节点所有对象链表
	Vector<cocos2d::Node*>::iterator fish, bullet;
	for (bullet = Children.begin(); bullet != Children.end();bullet++)
	{
		//8-30号是激光炮
		//1-7子弹来遍历出现在屏幕中的鱼 子弹的tag为1至7 鱼的tag为101-116
		int BulletTag = (*bullet)->getTag();
		//普通子弹碰撞判断
		if (BulletTag >= 1 && BulletTag <= 7)
		{
			//所有鱼
			for (fish = Children.begin(); fish != Children.end();fish++)
			{
				if ((*fish)->getTag() > 100)
				{
					int FishTag = (*fish)->getTag();
					auto fishRect = (*fish)->getBoundingBox();
					auto fishSize = (*fish)->getContentSize();
					//Vec2 LeftTop, RightTop, LeftDown, RightDown;
					
					if (fishRect.getMaxY() - fishRect.getMinY() > 90) {
						fishSize.height /= 2;//如果 是大鱼，碰撞框设置在鱼中间
					}
					Vec2 LeftTop = Vec2(fishRect.getMinX(), fishRect.getMaxY());
					Vec2 RightTop = Vec2(fishRect.getMaxX(), fishRect.getMaxY());
					Vec2 LeftDown = Vec2(fishRect.getMinX(), fishRect.getMinY());
					Vec2 RightDown = Vec2(fishRect.getMaxX(), fishRect.getMinY());

					//判断子弹与鱼的直线距离，判断子弹是否被 鱼包围
					if (ccpDistance((*bullet)->getPosition(), (*fish)->getPosition()) <= fishSize.height
						/*|| ccpDistance((*bullet)->getPosition(), RightTop) <= 40
						|| ccpDistance((*bullet)->getPosition(), LeftDown) <= 40
						|| ccpDistance((*bullet)->getPosition(), RightDown) <= 40*/
						
						|| (*bullet)->getPosition().x>fishRect.getMinX()&& (*bullet)->getPosition().x<fishRect.getMaxX()
						&& (*bullet)->getPosition().y>fishRect.getMinY()+ fishSize.height
						&& (*bullet)->getPosition().y<fishRect.getMaxY())
					{
						int sundID1 = SimpleAudioEngine::sharedEngine()->playEffect("music/Bombette.mp3");
						//碰撞后的鱼处理
						(*fish)->stopAllActions();
						auto fishPos = (*fish)->getPosition();
						auto fishAngle = (*fish)->getRotation();
						FishNode->removeChild((*fish));
						
						auto FishDeath = Sprite::create();
						FishDeath->setPosition(fishPos);
						FishDeath->setRotation(fishAngle);
						FishDeath->runAction(CCSequence::create(
							ACT_FTY->GetFishAct_ByTag(FishTag,1),
							CCCallFuncN::create(this, callfuncN_selector(gamescene::RemoveSpriteCallback)),
							NULL));

						//金币
						int sundID2 = SimpleAudioEngine::sharedEngine()->playEffect("music/bgm_coin_01.mp3");
						auto gold = Sprite::create();
						gold->setPosition(fishPos);
						gold->setTag(200 + (FishTag - 100) * 2);
						addChild(gold,2);
						gold->runAction(RepeatForever::create(ACT_FTY->Gold()));
						gold->runAction(CCSequence::create(
							MoveTo::create(2,Vec2(400,20)),
							CCCallFuncN::create(this, callfuncN_selector(gamescene::RemoveSpriteCallback)),
							NULL));

						addChild(FishDeath);

						//碰撞后的子弹处理
						(*bullet)->stopAllActions();
						auto bulletPos = (*bullet)->getPosition();
						auto bulletAngle = (*bullet)->getRotation();
						FishNode->removeChild((*bullet));
						
						auto BulletBoom = Sprite::create();
						BulletBoom->setPosition(bulletPos);
						BulletBoom->setRotation(bulletAngle);
						if (BulletTag < 5){
							BulletBoom->runAction(CCSequence::create(
								ACT_FTY->BullectBoom1(),
								CCCallFuncN::create(this, callfuncN_selector(gamescene::RemoveSpriteCallback)),
								NULL));
						}
						else {
							BulletBoom->runAction(CCSequence::create(
								ACT_FTY->BullectBoom2(),
								CCCallFuncN::create(this, callfuncN_selector(gamescene::RemoveSpriteCallback)),
								NULL));
						}
						addChild(BulletBoom);
						break;//一颗子弹只判断一条鱼
					}
					
				}
				else
					continue;
			}

		}
		//激光炮碰撞判断
		else if (BulletTag > 8 && BulletTag <= 30) {
			//here is jiGuangPao de collision;
			(*bullet)->setTag(--BulletTag);
			if (BulletTag >= 12 && BulletTag <= 21){
				for (fish = Children.begin(); fish != Children.end();fish++) {
					int FishTag = (*fish)->getTag();
					//	A   *****************	C
					//		*			  *	
					//		*		    *	
					//		*		  *		
					//		*		*		
					//		*	  *			
					//		*	*			
					//		* *				
					//	B	*
					float ac = abs((*fish)->getPosition().x - (*bullet)->getPosition().x);
					float ab = abs((*fish)->getPosition().y - (*bullet)->getPosition().y);
					float bc = sqrtf(ac*ac + ab*ab);
					float angle_abc = CC_RADIANS_TO_DEGREES((ac*ac + bc*bc - ab*ab) / (2 * ac*bc));
					if (angle_abc > 45) {
						angle_abc = 90 - CC_RADIANS_TO_DEGREES((ab*ab + bc*bc - ac*ac) / (2 * ab*bc));
					}
					float angle_pao = (*bullet)->getRotation();
					if ((*fish)->getPosition().x < (*bullet)->getPosition().x) {
						angle_abc = -angle_abc;
					}	//collision angle
					if (abs(angle_abc - angle_pao) <= 3) {
						(*fish)->stopAllActions();
						auto fishPos = (*fish)->getPosition();
						auto fishAngle = (*fish)->getRotation();
						FishNode->removeChild((*fish));

						auto FishDeath = Sprite::create();
						FishDeath->setPosition(fishPos);
						FishDeath->setRotation(fishAngle);
						FishDeath->runAction(CCSequence::create(
							ACT_FTY->GetFishAct_ByTag(FishTag, 1),
							CCCallFuncN::create(this, callfuncN_selector(gamescene::RemoveSpriteCallback)),
							NULL));
						//coin
						int sundID2 = SimpleAudioEngine::sharedEngine()->playEffect("music/bgm_coin_01.mp3");
						auto gold = Sprite::create();
						gold->setPosition(fishPos);
						gold->setTag(200 + (FishTag - 100) * 2);
						addChild(gold, 2);
						gold->runAction(RepeatForever::create(ACT_FTY->Gold()));
						gold->runAction(CCSequence::create(
							MoveTo::create(2, Vec2(400, 20)),
							CCCallFuncN::create(this, callfuncN_selector(gamescene::RemoveSpriteCallback)),
							NULL));

						addChild(FishDeath);
					}
				}

			}
			else
				continue;
		}
		else
			continue;
	}

}

void gamescene::FishFactory(float dt)
{
	static float FishTime = 0.f;//第一轮鱼 0-60s 小鱼

	GameTime += dt;FishTime += dt;

	if (GameTime >= 0 && GameTime <= 60)
		Now_Round = Round_one;
	/*else if (GameTime > 60 && GameTime <= 120)
		Now_Round = Round_two;
	else if (GameTime > 120 && GameTime < 180)
		Now_Round = Round_three;*/

	auto s = Director::getInstance()->getWinSize();
	
	
	int fish_tag = 100;
	bool Fish_Succed = false;
	float MoveTime = 0.f;
	{	//开始 造鱼  通过时间控制
		{	//第一轮
			switch (Now_Round)
			{
			case Round_one: {
				if (FishTime > 10)
					FishTime = 0.f;
				if (abs(FishTime - 1.f) <= 0.2f)
				{
					fish_tag = 101;Fish_Succed = true;
					MoveTime = CCRANDOM_0_1()*(15 - 10 + 1) + 10;
				}
				else if (abs(FishTime - 2.f) <= 0.2f)
				{
					fish_tag = 106;Fish_Succed = true;
					MoveTime = CCRANDOM_0_1()*(15 - 10 + 1) + 10;
				}
				else if (abs(FishTime - 3.f) <= 0.2f)
				{
					fish_tag = 107;Fish_Succed = true;
					MoveTime = CCRANDOM_0_1()*(15 - 10 + 1) + 10;
				}
				else if (abs(FishTime - 4.f) <= 0.2f)
				{
					fish_tag = 111;Fish_Succed = true;
					MoveTime = CCRANDOM_0_1()*(15 - 10 + 1) + 10;
				}
				else if (abs(FishTime - 5.f) <= 0.2f)
				{
					fish_tag = 104;Fish_Succed = true;
					MoveTime = CCRANDOM_0_1()*(15 - 10 + 1) + 10;
				}
				else if (abs(FishTime - 6.f) <= 0.2f)
				{
					fish_tag = 112;Fish_Succed = true;
					MoveTime = CCRANDOM_0_1()*(15 - 10 + 1) + 10;
				}
				else if (abs(FishTime - 7.f) <= 0.2f)
				{
					fish_tag = 113;Fish_Succed = true;
					MoveTime = CCRANDOM_0_1()*(15 - 10 + 1) + 10;
				}
				else if (abs(FishTime - 8.f) <= 0.2f)
				{
					fish_tag = 114;Fish_Succed = true;
					MoveTime = CCRANDOM_0_1()*(15 - 10 + 1) + 10;
				}
				else if (abs(FishTime - 9.f) <= 0.2f)
				{
					fish_tag = 115;Fish_Succed = true;
					MoveTime = CCRANDOM_0_1()*(15 - 10 + 1) + 10;
				}
			}break;
			case Round_two:break;
			case Round_three:break;
			default:
				break;
			}
			
		}
		

		
	}
	


	//第一轮造鱼
	if (Now_Round == Round_one) {
		if (Fish_Succed) {
			auto fish = Sprite::create();
			fish->setTag(fish_tag);
			fish->setPosition(s.width + fish->getContentSize().width, CCRANDOM_0_1()*(650 - 100 + 1) + 100);
			fish->runAction(RepeatForever::create(ACT_FTY->GetFishAct_ByTag(fish_tag)));//通过tag标签获取对应鱼的动作
			fish->runAction(CCSequence::create(
				MoveTo::create(MoveTime, Vec2(-fish->getContentSize().width - 200, CCRANDOM_0_1()*(650 - 100 + 1) + 100)),
				CCCallFuncN::create(this, callfuncN_selector(gamescene::RemoveSpriteCallback)),
				NULL));
			//fish->autorelease();//设置自动释放
			FishNode->addChild(fish, 1);
		}
	}
	
	
	
	
}

void gamescene::BulletFireCallback()
{
	Sprite* Bullet;//子弹精灵
	int Length;//子弹发射距离
	float BoomTime;//飞行时间
	std::string BulletName;//子弹纹理
	int m_tag;//子弹编号，1-4子弹编号1，5-7编号 2
	if (now_Arms == is_Pao) {
		switch (now_PaoNum)
		{
		case 0:
		{
			m_I_bufferNumber -= 1;
			Now_pao->runAction(ACT_FTY->cannon_1_fire());
			BulletName = "weapon_bullet_001.png";
			Length = 300;m_tag = 1;
			break;
		}
		case 1:
		{
			m_I_bufferNumber -= 2;
			Now_pao->runAction(ACT_FTY->cannon_2_fire());
			BulletName = "weapon_bullet_002.png";
			Length = 350;m_tag = 2;
			break;
		}
		case 2:
		{
			m_I_bufferNumber -= 3;
			Now_pao->runAction(ACT_FTY->cannon_3_fire());
			BulletName = "weapon_bullet_003.png";
			Length = 400;m_tag = 3;
			break;
		}
		case 3:
		{
			m_I_bufferNumber -= 4;
			Now_pao->runAction(ACT_FTY->cannon_4_fire());
			BulletName = "weapon_bullet_004.png";
			Length = 450;m_tag = 4;
			break;
		}
		case 4:
		{
			m_I_bufferNumber -= 5;
			Now_pao->runAction(ACT_FTY->cannon_5_fire());
			BulletName = "weapon_bullet_005.png";
			Length = 500;m_tag = 5;
			break;
		}
		case 5:
		{
			m_I_bufferNumber -= 6;
			Now_pao->runAction(ACT_FTY->cannon_6_fire());
			BulletName = "weapon_bullet_006.png";
			Length = 550;m_tag = 6;
			break;
		}
		case 6:
		{
			m_I_bufferNumber -= 7;
			Now_pao->runAction(ACT_FTY->cannon_7_fire());
			BulletName = "weapon_bullet_007.png";
			Length = 600;m_tag = 7;
			break;
		}
		default:break;
		}
		int sundID = SimpleAudioEngine::sharedEngine()->playEffect("music/bgm_fire.mp3");
		//单位向量
		Vec2 oneNormalize = ccpNormalize(m_TouchPoint - Now_pao->getPosition());
		//时间，控制子弹速度一致
		BoomTime = ccpDistance(Now_pao->getPosition() + oneNormalize*Length, Now_pao->getPosition()) / 600;

		Bullet = Sprite::createWithSpriteFrame(
			SpriteFrameCache::getInstance()->getSpriteFrameByName(BulletName));
		Bullet->setTag(m_tag);
		Bullet->setZOrder(2);
		Bullet->setPosition(Now_pao->getPosition());//坐标与炮台坐标相等
		Bullet->setRotation(Now_pao->getRotation());//角度与炮台角度相等
		Bullet->runAction(CCSequence::create(
			CCMoveTo::create(BoomTime, Now_pao->getPosition() + oneNormalize*Length),
			CCCallFuncN::create(this, callfuncN_selector(gamescene::BulletSuccedCallback)),
			NULL));
		FishNode->addChild(Bullet);
	}
	else {
		int sundID = SimpleAudioEngine::sharedEngine()->playEffect("music/bgm_ach.mp3");
		m_I_bufferNumber -= 50;//一炮五十
		Now_pao->runAction(ACT_FTY->cannon_jiguang_fire());
		Bullet = Sprite::create();
		Bullet->setTag(30);//其中15-20桢用来遍历 tag为8
		Bullet->setName("woshijiguang");
		Bullet->setZOrder(2);
		Bullet->setAnchorPoint(Vec2(0.5, 0));
		Bullet->setPosition(Now_pao->getPosition());//坐标与炮台坐标相等
		Bullet->setRotation(Now_pao->getRotation());//角度与炮台角度相等
		Bullet->runAction(CCSequence::create(
			ACT_FTY->cannon_jiguang_Boom(),
			CCCallFuncN::create(this, callfuncN_selector(gamescene::RemoveSpriteCallback)),
			NULL));
		FishNode->addChild(Bullet);
	}
	
}

void gamescene::BulletSuccedCallback(Node * Bullet)
{
	//子弹达到终点后

	Bullet->removeFromParentAndCleanup(true);
	addChild(Bullet);

	switch (Bullet->getTag())
	{
		//1号鱼网效果
	case 1:Bullet->runAction(CCSequence::create(ACT_FTY->BullectBoom1(),
		CCCallFuncN::create(this, callfuncN_selector(gamescene::RemoveSpriteCallback)),
		NULL));break;
	case 2:Bullet->runAction(CCSequence::create(ACT_FTY->BullectBoom1(),
		CCCallFuncN::create(this, callfuncN_selector(gamescene::RemoveSpriteCallback)),
		NULL));break;
	case 3:Bullet->runAction(CCSequence::create(ACT_FTY->BullectBoom1(),
		CCCallFuncN::create(this, callfuncN_selector(gamescene::RemoveSpriteCallback)),
		NULL));break;
	case 4:Bullet->runAction(CCSequence::create(ACT_FTY->BullectBoom1(),
		CCCallFuncN::create(this, callfuncN_selector(gamescene::RemoveSpriteCallback)),
		NULL));break;

		//2号鱼网效果
	case 5:Bullet->runAction(CCSequence::create(ACT_FTY->BullectBoom2(),
		CCCallFuncN::create(this, callfuncN_selector(gamescene::RemoveSpriteCallback)),
		NULL));break;
	case 6:Bullet->runAction(CCSequence::create(ACT_FTY->BullectBoom2(),
		CCCallFuncN::create(this, callfuncN_selector(gamescene::RemoveSpriteCallback)),
		NULL));break;
	case 7:Bullet->runAction(CCSequence::create(ACT_FTY->BullectBoom2(),
		CCCallFuncN::create(this, callfuncN_selector(gamescene::RemoveSpriteCallback)),
		NULL));break;
	default:
		break;
	}

	int sundID = SimpleAudioEngine::sharedEngine()->playEffect("music/Bombette.mp3");
}

void gamescene::RemoveSpriteCallback(Node * node)
{
	//如果 是金币精灵的话
	if (node->getTag() >= 200) {
		m_I_bufferNumber += node->getTag() - 200;
	}
	//如果是激光炮的话
	if (node->getName()== StringUtils::format("woshijiguang")) {
		JiguangEnd = true;
	}
	//清除精灵与精灵上的所有动作
	node->removeFromParentAndCleanup(true);
}

void gamescene::ScaleCallback()
{
	if (now_Arms == is_Pao) {
		JiguangPao->setVisible(false);
		if (Now_pao == JiguangPao) 
			angle = JiguangPao->getRotation();
		else
			angle = pao[last_PaoNum]->getRotation();

		pao[last_PaoNum]->setVisible(false);
		pao[now_PaoNum]->setVisible(true);
		pao[now_PaoNum]->setScale(pao[last_PaoNum]->getScale());
		pao[now_PaoNum]->setRotation(angle);
		last_PaoNum = now_PaoNum;
		Now_pao = pao[now_PaoNum];
		Now_pao->runAction(CCScaleTo::create(0.5f, 1.f));
		PaoChangeSucced = true;;
	}
	else if(now_Arms == is_Jiguang){
		angle = Now_pao->getRotation();
		JiguangPao->setScale(Now_pao->getScale());
		JiguangPao->setRotation(angle);
		Now_pao->setVisible(false);
		Now_pao = JiguangPao;
		Now_pao->setVisible(true);
		Now_pao->runAction(CCScaleTo::create(0.5f, 1.f));
		PaoChangeSucced = true;
	}
	
}
