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

    //mod = Client::GetModule("hide-btn");
    //mod2 = Client::GetModule("instant-fade");
    //canDrag = Client::GetModule("allow-dragging");

    menu = CCMenu::create();
    menu->setPosition(position);
    menu->setContentSize(ccp(0, 0));

    //l = CCLabelBMFont::create(">_", "bigFont.fnt");
    //l->setAnchorPoint(ccp(0.5f, 0.35f));

    btnOverlay = CCSprite::create(/*isColonThreeEnabled() ? "QOL_resources/sprites/qolmodButtonOverlaycolonthree.png" : */"QOL_resources/sprites/qolmodButtonOverlay.png");

    btn = CCSprite::create("QOL_resources/sprites/qolmodButtonBG.png");
    btn->addChildAtPosition(btnOverlay, Anchor::Center);
    menu->addChild(btn);
    
    this->addChild(menu);
    this->setZOrder(69420 - 1);
    this->scheduleUpdate();

    //UpdateVisible(true);

    return true;
}

void AndroidBall::update(float dt)
{
    //UpdateVisible(false);
}

void $(AppDelegate::willSwitchToScene)(AppDelegate* self, CCScene* newScene)
{
    $orig(self, newScene);
    
    if (!newScene)
        return;

    if (getChildOfType<LoadingLayer>(newScene, 0))
        return; // fixes texture ldr

    if (auto ball = getChildOfType<AndroidBall>(newScene, 0))
        ball->removeFromParent();

    newScene->addChild(AndroidBall::create());

    if (auto shop = getChildOfType<GJShopLayer>(newScene, 0))
    {
        handleTouchPriority(shop);
    }
}