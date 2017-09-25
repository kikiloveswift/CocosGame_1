#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "TestScene.hpp"
#include <iostream>

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
//    auto btn1 = MenuItem::create(CC_CALLBACK_1(HelloWorld::btnClick, this));
//    cocos2d::Color3B color1 = Color3B(255,255,255);
//    btn1 -> setColor(color1);
//    btn1 -> setPosition(Vec2(origin.x + visibleSize.width/2,
//                             origin.y + visibleSize.height - btn1->getContentSize().height - 100));
    
    MenuItemFont::setFontSize(32);    //设置字号
    MenuItemFont::setFontName("Marker Felt"); //设置字体
    MenuItemFont *btn1 = MenuItemFont::create("点击",CC_CALLBACK_1(HelloWorld::btnClick, this));//添加文字按钮，点击实现缩放
    btn1->setColor(Color3B(255, 0, 0));  //设置颜色
    
//    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
//                                origin.y + closeItem->getContentSize().height/2));


    // create menu, it's an autorelease object
    auto menu = Menu::create(btn1,closeItem, NULL);
    menu->setPosition(Vec2(origin.x + visibleSize.width - menu->getContentSize().width/2 ,
                           origin.y + menu->getContentSize().height/2 -100));
    menu -> alignItemsVertically();
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Holy Shit", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}

void HelloWorld::btnClick(Ref *btn)
{
    std::cout << "btn Click" << std::endl;
    Director::getInstance() -> replaceScene(TestScene::createScene());
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
