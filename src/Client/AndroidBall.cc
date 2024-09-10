#include "AndroidBall.hh"

AndroidBall* AndroidBall::get()
{
    return instance;
}

bool AndroidBall::init()
{
    if (!CCLayer::init())
        return false;

    this->setMouseEnabled(false);
    this->setTouchEnabled(true);

    highest++;
    this->setTag(highest);
    instance = this;

    menu = CCMenu::create();
    menu->setPosition(position);
    menu->setContentSize(ccp(0, 0));

    //l = CCLabelBMFont::create(">_", "bigFont.fnt");
    //l->setAnchorPoint(ccp(0.5f, 0.35f));

    btnOverlay = CCSprite::create("QOL_resources/sprites/qolmodButtonOverlay.png");

    btn = CCSprite::create("QOL_resources/sprites/qolmodButtonBG.png");
    menu->addChild(btn);
    
    this->addChild(menu);
    this->setZOrder(69420 - 1);
    this->scheduleUpdate();

    return true;
}

void AndroidBall::update(float dt)
{

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

    newScene->addChild(AndroidBall::create());
}