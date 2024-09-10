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

        CREATE_FUNC(AndroidBall);
        static AndroidBall* get();

        virtual bool init();

        virtual void update(float dt);

        ~AndroidBall();
};

/*class $modify (QOLModTouchDispatcher, CCTouchDispatcher)
{
    void touches(CCSet* touches, CCEvent* event, unsigned int type);
};*/