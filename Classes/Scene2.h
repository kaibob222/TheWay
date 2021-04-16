#ifndef __SCENE2_H__
#define __SCENE2_H__

#include "cocos2d.h"

class Scene2 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Scene2);

	cocos2d::Sprite *sprite1;
	cocos2d::Sprite* sprite2;

	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	bool isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

	void update(float dt);
	void Play(Ref *pSender);
	void Highscores(Ref *pSender);
	void Settings(Ref *pSender);
	void ImageButton(Ref *pSender);
	void Exit(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__