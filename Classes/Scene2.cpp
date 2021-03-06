#include "Scene2.h"
#include "AudioEngine.h"
#include "MenuMain.h"
#include "ui/CocosGUI.h"
#include "HelloWorldScene.h"
#include "GameOver.h"
#include "Anime.h"
#include "Hero.h"
#include "Enemy.h"

USING_NS_CC;

int q;
bool motion = false;
int xp = 3;

//Scene* Scene2::createScene()
//{
//	return Scene2::create();
//}
Scene* Scene2::createScene()
{
	auto scene2 = Scene2::createWithPhysics();
	scene2->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	scene2->getPhysicsWorld()->setGravity(Vec2(0, 0));

	auto layer = Scene2::create();
	layer->SetPhysicsWorld(scene2->getPhysicsWorld());
	scene2->addChild(layer);

	return scene2;
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

int musS2;
// on "init" you need to initialize your instance
bool Scene2::init()
{
	if (!Scene::init())
	{
		return false;
	}

	Director::getInstance()->getOpenGLView()->setFrameSize(900, 600);
	Director::getInstance()->getOpenGLView()->setDesignResolutionSize(900, 600, ResolutionPolicy::EXACT_FIT);


	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//music
	musS2 = AudioEngine::play2d("bg2.mp3", true, 1.0);
	///phy
	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	edgeNode->setPhysicsBody(edgeBody);

	this->addChild(edgeNode);


	///

	auto background = Sprite::create("scene2.jpg");
	if (background == nullptr)
	{
		problemLoading("'scene2.jpg'");
	}
	else
	{
		// position the sprite on the center of the screen
		background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(background, 0);
	}

	auto label = Label::createWithTTF("SCENE 2", "fonts/Marker Felt.ttf", 24);
	if (label == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}

	sprite1 = Sprite::create("Adv.png", Rect(1, 33, 137, 131));
	sprite1->setPosition(Point(50, 150));
	

    sprite2 = Sprite::create("enemy/Skelet2.png", Rect(20, 0, 170, 251));
	sprite2->setPosition(Point(700, 150)); //205 defolt
	

	Vector<SpriteFrame*> animFrames;
	bool key = false;

	if (key == false)
	{
		animFrames.reserve(15);
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(1580, 533, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(1580, 533, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(1820, 533, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(1820, 533, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(2080, 533, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(2080, 533, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(2340, 533, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(2340, 533, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(2585, 533, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(2585, 533, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(2840, 533, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(2840, 533, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(3100, 533, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(3100, 533, 170, 251)));
		/*animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(550, 533, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(800, 533, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(800, 533, 170, 251)));*/
		/*animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(2860, 785, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(3121, 785, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(3121, 785, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(3121, 785, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(3121, 785, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(3121, 785, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(3121, 785, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(2350, 785, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(2350, 785, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(2350, 785, 170, 251)));
		animFrames.pushBack(SpriteFrame::create("enemy/Skelet2.png", Rect(2350, 785, 170, 251)));*/

		Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
		Animate* animate = Animate::create(animation);
		sprite2->runAction(RepeatForever::create(animate));
	}
	
		//enemy physicsbody
	Enemy::enemyPhysics(sprite2);

		//hero physicsbody
	Hero::heroPhysics(sprite1);
	this->addChild(sprite1);
	this->addChild(sprite2);




	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(Scene2::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(Scene2::keyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

	auto menu_Item_1 = MenuItemFont::create("Exit", CC_CALLBACK_1(Scene2::Exit, this));
	auto menu_Item_2 = MenuItemImage::create("redheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
	auto menu_Item_3 = MenuItemImage::create("redheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
	auto menu_Item_4 = MenuItemImage::create("redheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));

	auto *menu = Menu::create(menu_Item_1, NULL);
	menu->alignItemsVertically();
	auto *menu2 = Menu::create(menu_Item_2, NULL);
	auto *menu3 = Menu::create(menu_Item_3, NULL);
	auto *menu4 = Menu::create(menu_Item_4, NULL);
	menu->setPosition(Point(850, 570));
	menu2->setPosition(Point(20, 570));
	menu3->setPosition(Point(60, 570));
	menu4->setPosition(Point(100, 570));
	this->addChild(menu);
	this->addChild(menu2);
	this->addChild(menu3);
	this->addChild(menu4);

	this->scheduleUpdate();

	if (xp == 2) {
		auto menu_Item_4 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
		auto *menu4 = Menu::create(menu_Item_4, NULL);
		menu4->setPosition(Point(100, 570));
		this->addChild(menu4);
	}
	if (xp == 1) {
		auto menu_Item_3 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
		auto *menu3 = Menu::create(menu_Item_3, NULL);
		menu3->setPosition(Point(60, 570));
		this->addChild(menu3);
		auto menu_Item_4 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
		auto *menu4 = Menu::create(menu_Item_4, NULL);
		menu4->setPosition(Point(100, 570));
		this->addChild(menu4);
	}
	if(abs(sprite2->getPositionX() - sprite1->getPositionX()) >= 150)
	this->enemyMoveFinished(sprite2);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Scene2::onContactBegin2, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	return true;
}

bool isPaused1 = false;
int q112 = 0;
void Scene2::enemyMoveFinished(cocos2d::Ref* pSpender)
{
	Sprite* Enemy = (Sprite*)pSpender;
	this->animateEnemy(Enemy);
	
}
void Scene2::Hurt(cocos2d::Ref* pSpender) {

	xp--;
	if (xp == 2) {
		auto menu_Item_4 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
		auto *menu4 = Menu::create(menu_Item_4, NULL);
		menu4->setPosition(Point(100, 570));
		this->addChild(menu4);
		Hero::heroHurt(sprite1);
	}
	if (xp == 1) {
		auto menu_Item_3 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
		auto *menu3 = Menu::create(menu_Item_3, NULL);
		menu3->setPosition(Point(60, 570));
		this->addChild(menu3);
		Hero::heroHurt(sprite1);
	}
	if (xp == 0) {
		Hero::heroDeath(sprite1);
		isPaused1 = true;
		auto menu_Item_2 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
		auto *menu2 = Menu::create(menu_Item_2, NULL);
		menu2->setPosition(Point(20, 570));
		this->addChild(menu2);
		xp = 3;
	}
	Hero::heroHurt(sprite1);
}
void Scene2::animateEnemy(cocos2d::Ref* pSpender)
{
	Sprite* Enemy = (Sprite*)pSpender;

	/*if ((abs(Enemy->getPositionX() - sprite1->getPositionX()) <= 150))
	Scene2::Hurt(pSpender);*/

	float actualDuration = 0.3f;

	auto position = (sprite1->getPosition() - Enemy->getPosition());
	position.normalize();
	auto actionMove = MoveBy::create(actualDuration, position.operator * (10));
	auto actionMoveDone = CallFuncN::create(CC_CALLBACK_1(Scene2::enemyMoveFinished, this));
	if ((abs(Enemy->getPositionX() - sprite1->getPositionX()) >= 120))
	Enemy->runAction(Sequence::create(actionMove, actionMoveDone, NULL));

	if ((abs(Enemy->getPositionX() - sprite1->getPositionX()) <= 150))
	{

		
		
	}
}



bool Scene2::onContactBegin2(PhysicsContact& contact)
{
	auto *nodeA = contact.getShapeA()->getBody();
	auto *nodeB = contact.getShapeB()->getBody();

	if ((1 == nodeA->getCollisionBitmask() && 2 == nodeB->getCollisionBitmask()) || (2 == nodeA->getCollisionBitmask() && 1 == nodeB->getCollisionBitmask()))
	{
		CCLOG("COLLISION HAS OCCURED ");
		xp--;
		//sprite1->_physicsBody->applyImpulse(Vec2(-100, 0));
		if (xp == 2) {
			auto menu_Item_4 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
			auto *menu4 = Menu::create(menu_Item_4, NULL);
			menu4->setPosition(Point(100, 570));
			this->addChild(menu4);
			Hero::heroHurt(sprite1);
		}
		if (xp == 1) {
			auto menu_Item_3 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
			auto *menu3 = Menu::create(menu_Item_3, NULL);
			menu3->setPosition(Point(60, 570));
			this->addChild(menu3);
			Hero::heroHurt(sprite1);
		}
		if (xp == 0) {
			Hero::heroDeath(sprite1);
			isPaused1 = true;
			auto menu_Item_2 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
			auto *menu2 = Menu::create(menu_Item_2, NULL);
			menu2->setPosition(Point(20, 570));
			this->addChild(menu2);
			xp = 3;
		}
	}

	return true;
}

void Scene2::Heart(cocos2d::Ref *pSpender)
{
	CCLOG("Image Button");
}

void Scene2::update(float dt) {
	Point pos = sprite1->getPosition();

	if (pos < Point(50, 150)) {
		q = 1;
		auto scene = HelloWorld::createScene();
		AudioEngine::stop(musS2);
		Director::getInstance()->replaceScene(scene);
	}
	if (isPaused1)
	{
		q112++;
		if (q112 == 100)
		{
			auto scene = GameOver::createScene();
			Director::getInstance()->replaceScene(scene);
			q112 = 0;
			isPaused1 = false;
		}
	}
	
	}


void Scene2::Exit(cocos2d::Ref *pSpender)
{
	CCLOG("Exit");
	AudioEngine::stopAll();
	auto scene = MenuMain::createScene();
	Director::getInstance()->replaceScene(scene);

}

void Scene2::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	CCLOG("Key with keycode %d pressed", keyCode);
	Point pos = sprite1->getPosition();
	if ((int)keyCode == 164)
	{
		xp--;
		if (xp == 2) {
			auto menu_Item_4 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
			auto *menu4 = Menu::create(menu_Item_4, NULL);
			menu4->setPosition(Point(100, 570));
			this->addChild(menu4);
			Hero::heroHurt(sprite1);
		}
		if (xp == 1) {
			auto menu_Item_3 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
			auto *menu3 = Menu::create(menu_Item_3, NULL);
			menu3->setPosition(Point(60, 570));
			this->addChild(menu3);
			Hero::heroHurt(sprite1);
		}
		if (xp == 0) {
			Hero::heroDeath(sprite1);
			isPaused1 = true;
			auto menu_Item_2 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
			auto *menu2 = Menu::create(menu_Item_2, NULL);
			menu2->setPosition(Point(20, 570));
			this->addChild(menu2);
			xp = 3;
		}
	}

	if ((int)keyCode == 127 || (int)keyCode == 27)//keys D or -> pressed
	{
		for (int i = 1; i <= 8; i++)
		{
			sprite1->stopActionByTag(i);
		}
		Hero::goRight(sprite1);
	}
	if ((int)keyCode == 124 || (int)keyCode == 26)//keys A or <- pressed
	{
		for (int i = 1; i <= 8; i++)
		{
			sprite1->stopActionByTag(i);
		}
		Hero::goLeft(sprite1);
	}
	if ((int)keyCode == 133)//key J pressed
	{
		for (int i = 1; i <= 8; i++)
		{
			sprite1->stopActionByTag(i);
		}
		Hero::heroPunch(sprite1);
		if (abs(sprite2->getPositionX() - sprite1->getPositionX()) < 120) {
			sprite2->setRotation(-90);
			sprite2->setPositionY(sprite2->getPositionY() - 50);
			sprite2->removeComponent(sprite2->getPhysicsBody());
			//sprite2->setPhysicsBody(nullptr);
		}
	}
	if ((int)keyCode == 59)//key Space was pressed
	{
		int jump;
		jump = AudioEngine::play2d("jump1.mp3", false);
		Hero::heroJump(sprite1);
	}
	if ((int)keyCode == 164)//key Enter was pressed
	{
		Hero::heroHurt(sprite1);
	}
	/*if ((int)keyCode == 139)//key P was pressed
	{
		Hero::heroDeath(sprite1);
	}*/
}

void Scene2::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	for (int i = 1; i <= 4; i++)
	{
		sprite1->stopActionByTag(i);
	}
	Hero::heroStop(sprite1);
}

void Scene2::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}