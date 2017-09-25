//
//  TestScene.cpp
//  CocosGame_1-mobile
//
//  Created by kong on 2017/9/25.
//

#include "TestScene.hpp"
#include "SimpleAudioEngine.h"
USING_NS_CC;

Scene* TestScene::createScene()
{
    return TestScene::create();
}

bool TestScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    auto visiable = Director::getInstance() -> getVisibleSize();
    
    Vec2 vecs = Director::getInstance() -> getVisibleOrigin();
    auto label = Label::createWithTTF("Another Scene", "fonts/arial.ttf", 26);
    label -> setPosition(vecs.x + visiable.width/2, vecs.y + visiable.height /2);
    this -> addChild(label, 1);
    return true;
}

