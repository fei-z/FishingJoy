
#ifndef ActionFactory_hpp
#define ActionFactory_hpp
#define ACT_FTY ActionFactory::getInstance()
#include"Header.h"

//动作工厂 子弹、鱼、等动作资源
//plist已在loading中加载
class ActionFactory
{
private:
	//小鱼-紫
	Animate*fish_1_Move();
	Animate*fish_1_Die();
	//中鱼-金
	Animate*fish_2_Move();
	Animate*fish_2_Die();
	//中鱼-蓝
	Animate*fish_3_Move();
	Animate*fish_3_Die();
	//王八-小
	Animate*fish_4_Move();
	Animate*fish_4_Die();

	//电蟃 蓝色  大
	Animate*fish_5_Move();
	Animate*fish_5_Die();

	//金鱼-小
	Animate*fish_6_Move();
	Animate*fish_6_Die();

	//花鱼-小
	Animate*fish_7_Move();
	Animate*fish_7_Die();

	//大鲨鱼-金
	Animate*fish_8_Move();
	Animate*fish_8_Die();

	//大鲨鱼-蓝
	Animate*fish_9_Move();
	Animate*fish_9_Die();

	//电鱼-小-头上带天线
	Animate*fish_10_Move();
	Animate*fish_10_Die();

	//超小鱼
	Animate*fish_11_Move();
	Animate*fish_11_Die();

	//超小鱼-彩色
	Animate*fish_12_Move();
	Animate*fish_12_Die();

	//小鱼-蓝色
	Animate*fish_13_Move();
	Animate*fish_13_Die();

	//小鱼-红白色
	Animate*fish_14_Move();
	Animate*fish_14_Die();

	//小鱼-白色
	Animate*fish_15_Move();
	Animate*fish_15_Die();

	//小鱼-白色
	Animate*fish_16_Move1();//小游
	Animate*fish_16_Move2();//大游
	Animate*fish_16_Die();

	static ActionFactory*Instance;
public:
	static ActionFactory*getInstance();
	//通过鱼的当前tag标签获取动作,type为1获取死亡动作，默认获取移动的动作
	Animate*GetFishAct_ByTag(int tag, int type = 0);
	//炮台发射动作
	Animate*cannon_1_fire();
	Animate*cannon_2_fire();
	Animate*cannon_3_fire();
	Animate*cannon_4_fire();
	Animate*cannon_5_fire();
	Animate*cannon_6_fire();
	Animate*cannon_7_fire();
	Animate*cannon_jiguang_fire();
	Animate*cannon_jiguang_Boom();
	//子弹爆炸
	Animate*BullectBoom1();
	Animate*BullectBoom2();
	//彩虹
	Animate*caiHong();
	//金币
	Animate*Gold();
	//技能选中框
	Animate*Select();
	
};

#endif /* ActionFactory_hpp */