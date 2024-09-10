#include "AndroidBall.hh"

static AndroidBall* AndroidBall::get()
{
    return instance;
}

void AndroidBall::show(CCLayer* layer) 
{
    layer->addChild(m_layer, 69420 - 1);
}

AndroidBall::AndroidBall()
{
    m_layer = CCLayer::create();
    m_layer->setTouchEnabled(true);

    highest++;
    m_layer->setTag(highest);
    instance = m_layer;

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

    newScene->addChild(AndroidBall::get()->show(newScene));
}