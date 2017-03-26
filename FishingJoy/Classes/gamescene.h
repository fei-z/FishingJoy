#ifndef gamescene_hpp
#define gamescene_hpp

#include"Header.h"
//Z值	炮台3 子弹2 鱼1
//tag	子弹1-7	鱼101-
class gamescene :public Layer
{
private:
	//遍历鱼与子弹碰撞，每0.2秒执行一次
	void collision(float dt);
	//造鱼工厂,1秒执行一次
	void FishFactory(float dt);

	//炮台角度到位后的回调函数 子弹在这里发射
	void BulletFireCallback();
	//子弹击中目标后或者到达子弹射程时的回调
	void BulletSuccedCallback(Node *Bullet);
	//全部动作执行完成后的回调，删除子弹与鱼的精灵
	void RemoveSpriteCallback(Node *node);
	//炮台切换时缩放精灵的回调
	void ScaleCallback();
	//节点中压入鱼与子弹，用于遍历
	Node*FishNode;//Z排序为2
	Node*PauseNode;
	Node*rechargeNode;//充值界面
	enum fishFactory_Round {
		Round_one,
		Round_two,
		Round_three,
	}Now_Round;
	enum Arms {
		is_Pao,
		is_Jiguang,
	}now_Arms;
private:
	int last_PaoNum;//上一次炮台序号 用于判断
	int all_PaoNum;//炮台的总数
	int now_PaoNum;//当前炮序号

	bool PaoChangeSucced;//切换炮台是否完成，
	
	Sprite*pao[8];//炮台精灵
	Sprite*Now_pao;//当前显示炮台
	Sprite*JiguangPao;//激光炮
	float angle;//炮台旋转角度
	Vec2 m_TouchPoint;//鼠标点
	bool JiguangEnd;//激光是否发射完毕，完毕后才能发下一炮

	Sprite*BackScene;

	TextAtlas*money;//金币显示的文本
	int m_I_number;
	int m_I_bufferNumber;
	float GameTime;//游戏运行时间，用于控制鱼的出场 
public:
	static cocos2d::Scene* createScene();
	//按钮+
	void buttonJiaClickCallback(cocos2d::Ref* pSender);
	//按钮-
	void buttonJianClickCallback(cocos2d::Ref* pSender);
	//截屏按钮
	void CameraButtonCallback(Ref *pSender);
	//更换背景音乐按钮
	void ChangeBackMusicCallback(Ref *pSender);
	//暂停回调
	void PauseMenuCallback(Ref*pSender);
	//继续回调
	void ContinueGameCallback(Ref*pSender);
	//回到主菜单
	void sceneTomainCallback(Ref*pSender);
	//购买激光炮
	void jiguangPaoCallback(Ref*pSender);
	//切换 到普通炮
	void putongPaoCallback(Ref*pSender);
	virtual bool init();
	virtual void update(float dt);
	//触摸点击
	bool onTouchBegan(Touch*touch, Event* event);
	//滑动操作
	void onTouchMoved(Touch*touch, Event *event);
	//离开屏幕
	void onTouchEnded(Touch*touch, Event *event);
	

	CREATE_FUNC(gamescene);


};

#endif /* gamescene_hpp */
