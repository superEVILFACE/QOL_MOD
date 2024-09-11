#include "AndroidBall.hh"

AndroidBall& AndroidBall::get()
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

    menu = CCMenu::create();
    menu->setPosition(position);
    menu->setContentSize(ccp(0, 0));

    btn = CCSprite::create("QOL_resources/sprites/qolmodButtonBG.png");
    menu->addChild(btn);

    m_layer->addChild(menu);
    m_layer->schedule(CC_SCHEDULE_SELECTOR(AndroidBall::update), "update_key");
}

void AndroidBall::update(float dt) 
{
    // TODO
}

void* $(AppDelegate::willSwitchToScene)(AppDelegate* self, CCScene* newScene)
{
    $orig(self, newScene);
    
    if (!newScene)
        return nullptr;

    AndroidBall::get().show(newScene);
}
