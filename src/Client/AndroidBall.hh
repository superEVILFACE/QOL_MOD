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

        //Module* mod = nullptr; TODO
        //Module* mod2 = nullptr; TODO
        //Module* canDrag = nullptr; TODO

        CREATE_FUNC(AndroidBall);
        static AndroidBall* get();

        //bool isColonThreeEnabled(); TODO
        //void setColonThreeEnabled(); TODO

        //void onOpenMenu(); TODO

        virtual bool init();

        //bool _ccTouchBegan(CCTouch* touch, CCEvent* event); TODO
        //bool _ccTouchEnded(CCTouch* touch, CCEvent* event); TODO
        //bool _ccTouchMoved(CCTouch* touch, CCEvent* event); TODO

        virtual void update(float dt);
        //static float clampf(float v, float min, float max); TODO

        //void UpdateVisible(bool i); TODO

        ~AndroidBall();
};

/*class $modify (QOLModTouchDispatcher, CCTouchDispatcher)
{
    void touches(CCSet* touches, CCEvent* event, unsigned int type);
};*/