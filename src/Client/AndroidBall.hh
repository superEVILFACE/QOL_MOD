#pragma once

#include <auby.hh>

class AndroidBall
{
    public:
        static AndroidBall& get();

        void show(CCNode* layer);
        void update(float dt);

        static inline bool hasPos = false;
        static inline CCPoint position = ccp(32, CCDirector::sharedDirector()->getWinSize().height / 2);
        static inline int highest = 0;

        bool doingThing = false;
        static inline bool dragging = false;
        CCSprite* btnOverlay;
        CCSprite* btn;
        CCLabelBMFont* l;
        CCMenu* menu;

        AndroidBall();
        
    private:
        CCLayer* m_layer = nullptr;
};
