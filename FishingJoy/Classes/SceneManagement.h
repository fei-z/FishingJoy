#ifndef SceneManagement_hpp
#define SceneManagement_hpp

#include "Header.h"

#include"gamescene.h"
#include"gamelogo.h"
#include"mainscene.h"
#include"loadscene.h"

class scenemanagement
{
private:
	scenemanagement();
	~scenemanagement();
	//scenemanagement ~scenemanagement();
	static Scene*Logo_scene;
	static Scene*Main_scene;
	static Scene*Load_scene;
	static Scene*Game_scene;
	static scenemanagement*Instance;
public:
	static scenemanagement*getInstance();
	void sceneToLogo();
	void sceneToMain();
	void sceneToLoad();
	void sceneToGame();
	
};

#endif /* SceneManagement_hpp */