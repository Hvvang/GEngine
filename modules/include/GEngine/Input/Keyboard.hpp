#pragma once

#include <MiniKit/MiniKit.hpp>

#include <set>

namespace GEngine::Input {
    class Keyboard {
    public:
        static bool isKeyPressed(::MiniKit::Platform::Keycode button) {
            return _pressedKeys.count(button);
        }

    private:
        static ::std::set<::MiniKit::Platform::Keycode> _pressedKeys;

    friend class InputManager;
    };
}
