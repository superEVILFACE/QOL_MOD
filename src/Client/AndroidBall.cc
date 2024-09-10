#include "AndroidBall.hh"

AndroidBall* AndroidBall::get()
{
    static auto androidBall = AndroidBall();
    return androidBall;
}

void AndroidBall::show(CCNode* layer) 
{
    layer->addChild(m_layer, 69420 - 1);
}

AndroidBall::AndroidBall()
{
    m_layer = CCLayer::create();
    m_layer->setTouchEnabled(true);

    highest++;
    m_layer->setTag(highest);

    m_layer->setPosition(CCDirector::sharedDirector()->getWinSize() / 2);
}

AndroidBall::~AndroidBall()
{
    instance = nullptr;
}

void* $(AppDelegate::willSwitchToScene)(AppDelegate* self, CCScene* newScene)
{
    $orig(self, newScene);
    
    if (!newScene)
        return nullptr;

    AndroidBall::get()->show(newScene);
}