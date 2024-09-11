#pragma once

#include <auby.hh>

class AndroidBall : public CCLayer
{
    public:
        static inline bool hasPos = false;
        static inline CCPoint position = ccp(32, CCDirector::sharedDirector()->getWinSize().height / 2);
        static inline AndroidBall* instance = nullptr;
        static inline int highest = 0;

        bool doingThing = false;
        static inline bool dragging = false;
        CCSprite* btnOverlay;
        CCSprite* btn;
        CCLabelBMFont* l;
        CCMenu* menu;

        //Module* mod = nullptr;
        //Module* mod2 = nullptr;
        //Module* canDrag = nullptr;

        CREATE_FUNC(AndroidBall);
        static AndroidBall* get();

        //bool isColonThreeEnabled();
        //void setColonThreeEnabled();

        //void onOpenMenu();

        virtual bool init();

        bool ccTouchBegan(CCTouch* touch, CCEvent* event);
        bool ccTouchEnded(CCTouch* touch, CCEvent* event);
        bool ccTouchMoved(CCTouch* touch, CCEvent* event);

        virtual void update(float dt);
        static float clampf(float v, float min, float max);

        //void UpdateVisible(bool i);

        ~AndroidBall();
};