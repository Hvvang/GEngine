#pragma once

#include <iostream>

namespace GEngine::Event {
    class GEvent {
    public:

        enum Type {
            KeyPress,
            KeyRelease,
            MouseButtonPress,
            MouseButtonRelease,
            MouseMove,

            FirstCustomEvent = 100,
            LastCustomEvent = 60000,
            Unknown,
        } type{Unknown};

        GEvent(Type type) : type(type) {}

    protected:
        virtual ~GEvent() {};
    };
}