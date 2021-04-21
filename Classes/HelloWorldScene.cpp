#include "HelloWorldScene.h"
#include "MenuMain.h"
#include "ui/CocosGUI.h"
#include "Scene2.h"
#include "Anime.h"

USING_NS_CC;

extern int q;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	if (!Scene::init())
	{
		return false;
	}

	Director::getInstance()->getOpenGLView()->setFrameSize(900, 600);
	Director::getInstance()->getOpenGLView()->setDesignResolutionSize(900, 600, ResolutionPolicy::EXACT_FIT);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("2.png");
	if (background == nullptr)
	{
		problemLoading("'2.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(background, 0);
	}
	
	auto label = Label::createWithTTF("SCENE 1", "fonts/Marker Felt.ttf", 24);
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
	
	if (q == 0) {
		sprite1 = Sprite::create("Adv.png", Rect(1, 33, 137, 131));
		sprite1->setPosition(Point(50, 150));
		q = 0;
	}
	if (q == 1) {
		sprite1 = Sprite::create("Adv.png", Rect(18, 1264, 137, 131));
		sprite1->setPosition(Point(880, 150));
		q = 0;
	}

	this->addChild(sprite1);

	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(HelloWorld::keyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);// if you are using cocos2d-x 3.0alpha.1 and later!// if you are using cocos2d-x 3.0alpha.1 and later!

	auto menu_Item_1 = MenuItemFont::create("Exit", CC_CALLBACK_1(HelloWorld::Exit, this));
	auto *menu = Menu::create(menu_Item_1, NULL);
	menu->alignItemsVertically();
	menu->setPosition(Point(850, 570));
	this->addChild(menu);

	this->scheduleUpdate();
	return true;
}

bool isJumping = false;
bool isRight = false;
float jumpForce = 10;
int maxJump = 40;
bool isWalking = false;
//bool grounded = true;
bool isPunching = false;
bool moveRight = false;
bool moveLeft = false;
bool goDown = false;

void HelloWorld::update(float dt) {
	Point pos = sprite1->getPosition();

	if (pos > Point(880, 150)) {
		auto scene = Scene2::createScene();
		Director::getInstance()->replaceScene(scene);
	}

	/*if (isJumping && !isWalking)
	{
		if (jumpForce < maxJump)
		{
			sprite1->setPosition(Point(pos.x, pos.y + jumpForce));
			jumpForce += 5;
		}
		else
		{
			isJumping = false;
			goDown = true;
		}
	}
	if (isJumping == false && pos.y > 110)
	{
		goDown = true;
		//grounded = false;
	}
	else
	{
		if (pos.y == 110)
		{
			goDown = false;
			//grounded = true;
			moveRight = false;  
			moveLeft = false;
		}
	}
	Point gravity = Point(0, -5);
	if (goDown) {
		if (pos.y > 110)
		{
			sprite1->setPosition(pos.x+gravity.x, pos.y + gravity.y);
			//grounded = false;
		}
		else
		{
			if (pos.y == 110)
			{
				isJumping = false;
				goDown = false;
				//grounded = true;
			}
		}

	}
	/*if (moveRight) {
		if (pos.y > 150)
		{
			float x = 2.5;
			float y = 2 * x;
			sprite1->setPosition(pos.x + x, pos.y - y);
			x -= 0.5;
			//moveRight = false;
			//goDown = true;
		}
		//moveRight = false;
		//goDown = true;
	}*/
	/*if (isJumping && jumpForce < maxJump) {
		ActionInterval* jump = JumpTo::create(0.5, Point(pos.x, pos.y), jumpForce++, 1);
		sprite1->runAction(jump);
	}*/
	/*if (pos.y <= 150 && pos.y >= 140) {
		grounded = true;
		moveLeft = false;
		moveRight = false;
	}
	else {
		grounded = false;
	}*/
}

void HelloWorld::Exit(cocos2d::Ref *pSpender)
{
	CCLOG("Exit");
	auto scene = MenuMain::createScene();
	Director::getInstance()->replaceScene(scene);
}

void HelloWorld::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	CCLOG("Key with keycode %d pressed", keyCode);
	Point pos = sprite1->getPosition();
	if ((int)keyCode == 127 || (int)keyCode == 27)//keys D or -> pressed
	{
		if (isPunching)
		{
			Animate* nopunchanimate = Animate::create(Anim::noRightPunch());
			sprite1->runAction(nopunchanimate);
			isPunching = false;
		}
		isWalking = true;
		isRight = true;
		if (!isJumping)//(grounded)
		{
			ActionInterval* move = MoveBy::create(0.15, Point(50, 0));
			auto repeatForever = cocos2d::RepeatForever::create(Sequence::create(move, move, NULL));
			repeatForever->setTag(1);
			sprite1->runAction(repeatForever);
			Animate* animate = Animate::create(Anim::walkRight());
			auto repAnimate = cocos2d::RepeatForever::create(RepeatForever::create(animate));
			repAnimate->setTag(2);
			sprite1->runAction(repAnimate);
		}
		else {
			moveRight = true;
		}
	}
	if ((int)keyCode == 124 || (int)keyCode == 26)//keys A or <- pressed
	{
		if (isPunching)
		{
			Animate* noLeftpunchanimate = Animate::create(Anim::noLeftPunch());
			sprite1->runAction(noLeftpunchanimate);
			isPunching = false;
		}
		isWalking = true;
		isRight = false;
		if (!isJumping)//(grounded)
		{
			ActionInterval* move1 = MoveBy::create(0.15, Point(-50, 0));
			auto repeatForever1 = cocos2d::RepeatForever::create(Sequence::create(move1, move1, NULL));
			repeatForever1->setTag(3);
			sprite1->runAction(repeatForever1);
			Animate* animate1 = Animate::create(Anim::walkLeft());
			auto repAnimate1 = cocos2d::RepeatForever::create(RepeatForever::create(animate1));
			repAnimate1->setTag(4);
			sprite1->runAction(repAnimate1);
		}
		else {
			moveLeft = true;
		}
	}
	if ((int)keyCode == 133)//key J pressed
	{
		if (!isWalking)
		{
			if (!isPunching)
			{
				if (isRight)
				{
					Animate* punchanimate = Animate::create(Anim::rightPunch());
					sprite1->runAction(punchanimate);
					isPunching = true;
				}
				else
				{
					Animate* punchLeftanimate = Animate::create(Anim::leftPunch());
					sprite1->runAction(punchLeftanimate);
					isPunching = true;
				}
			}
			else
			{
				if (isRight)
				{
					Animate* punchianimate = Animate::create(Anim::rightPunchi());
					sprite1->runAction(punchianimate);
				}
				else
				{
					Animate* punchiLeftanimate = Animate::create(Anim::leftPunchi());
					sprite1->runAction(punchiLeftanimate);
				}
			}
		}
	}
	if ((int)keyCode == 59)//key Space was pressed
	{
		Point posi = sprite1->getPosition();
		if (posi.y==150)
		{
			if (isWalking)
			{
				if (isRight)
				{
					isJumping = true;
					Animate* Jumpanimate = Animate::create(Anim::rightJump());
					ActionInterval* jump = JumpBy::create(0.5, Point(60, 0), 60, 1);
					sprite1->runAction(jump);
					sprite1->runAction(Jumpanimate);
					//isJumping = false;
				}
				else
				{
					isJumping = true;
					Animate* JumpLeftanimate = Animate::create(Anim::leftJump());
					ActionInterval* jump1 = JumpBy::create(0.5, Point(-60, 0), 60, 1);
					sprite1->runAction(jump1);
					sprite1->runAction(JumpLeftanimate);
					//isJumping = false;
				}
			}
			else
			{
				if (isRight)
				{
					isJumping = true;
					Animate* Jumpanimate = Animate::create(Anim::rightJump());
					ActionInterval* jump = JumpBy::create(0.5, Point(0, 0), 60, 1);
					sprite1->runAction(jump);
					sprite1->runAction(Jumpanimate);
					//isJumping = false;
				}
				else
				{
					isJumping = true;
					Animate* JumpLeftanimate = Animate::create(Anim::leftJump());
					ActionInterval* jump1 = JumpBy::create(0.5, Point(0, 0), 60, 1);
					sprite1->runAction(jump1);
					sprite1->runAction(JumpLeftanimate);
					//isJumping = false;
				}
			}
		}
		isJumping = false;
	}
	
}

void HelloWorld::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	sprite1->stopActionByTag(1);
	sprite1->stopActionByTag(2);
	sprite1->stopActionByTag(3);
	sprite1->stopActionByTag(4);
	isWalking = false;
	/*if (isJumping)
	{
		goDown = true;
		isJumping = false;
	}*/
	if (isRight) {
		sprite1->setTexture("Adv.png");
		sprite1->setTextureRect(Rect(1, 33, 137, 131));
	}
	else {
		sprite1->setTexture("Adv.png");
		sprite1->setTextureRect(Rect(18, 1264, 137, 131));
	}
	jumpForce = 10;
	//isJumping = false;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}
