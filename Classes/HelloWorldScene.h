#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	cocos2d::Sprite *sprite1;

	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	bool isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

	void Exit(Ref *pSender);
	//void Pause(Ref *pSender);
	//void Start(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__
