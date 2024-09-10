#include <auby.hh>
#include "Client/AndroidBall.hh"

namespace
{

    bool $(MenuLayer::init)(MenuLayer* self)
    {
        $orig(self);

        AndroidBall::position = ccp(32, CCDirector::get()->getWinSize().height / 2);
        return true;
    }

}