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
	bool onContactBegin2(cocos2d::PhysicsContact &contact);
	void update(float dt);
	void Play(Ref *pSender);
	void Highscores(Ref *pSender);
	void Settings(Ref *pSender);
	void ImageButton(Ref *pSender);
	void Exit(Ref *pSender);
	void Heart(Ref *pSender);
	void animateEnemy(Ref* pSender);
	void enemyMoveFinished(Ref *pSender);
    void Hurt(Ref *pSender);
	//void onContactBegin(PhysicsContact& contact);
	//void tick(float dt);
private:
	cocos2d::PhysicsWorld *sceneWorld;

	void SetPhysicsWorld(cocos2d::PhysicsWorld *world) {
		sceneWorld = world;
	};
};

#endif
