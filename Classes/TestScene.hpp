//
//  TestScene.hpp
//  CocosGame_1-mobile
//
//  Created by kong on 2017/9/25.
//

#ifndef TestScene_hpp
#define TestScene_hpp

#include "cocos2d.h"

class TestScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    //    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // 就是一个初始化
    CREATE_FUNC(TestScene);
};

#endif /* TestScene_hpp */

