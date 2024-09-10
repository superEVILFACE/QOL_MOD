#include "AndroidBall.hh"

AndroidBall* AndroidBall::get()
{
    return instance;
}

bool AndroidBall::init()
{
    if (!CCLayer::init())
        return false;

    this->setTouchEnabled(true);

    highest++;
    this->setTag(highest);
    instance = this;

    //mod = Client::GetModule("hide-btn");
    //mod2 = Client::GetModule("instant-fade");
    //canDrag = Client::GetModule("allow-dragging");

    menu = CCMenu::create();
    menu->setPosition(position);
    menu->setContentSize(ccp(0, 0));

    //l = CCLabelBMFont::create(">_", "bigFont.fnt");
    //l->setAnchorPoint(ccp(0.5f, 0.35f));

    btnOverlay = CCSprite::create("qolmodButtonOverlay.png");

    btn = CCSprite::create("qolmodButtonBG.png"_spr);
    //btn->addChildAtPosition(btnOverlay, Anchor::Center);
    menu->addChild(btn);
    
    this->addChild(menu);
    this->setZOrder(69420 - 1);
    this->scheduleUpdate();

    //UpdateVisible(true);

    return true;
}

AndroidBall::~AndroidBall()
{
    instance = nullptr;
}

float AndroidBall::clampf(float v, float min, float max)
{
    if (v < min)
        v = min;

    if (v > max)
        v = max;

    return v;
}

void* $(AppDelegate::willSwitchToScene)(AppDelegate* self, CCScene* newScene)
{
    $orig(self, newScene);
    
    if (!newScene)
        return nullptr;

    newScene->addChild(AndroidBall::create());
}