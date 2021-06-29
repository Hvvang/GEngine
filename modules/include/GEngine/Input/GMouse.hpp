#pragma once

#include <MiniKit/MiniKit.hpp>
#include <GEngine/Math/GVector.hpp>

#include <set>

using namespace GEngine::Math;

namespace GEngine::Input {
    class GMouse {
    public:
        static bool isButtonPressed(::MiniKit::Platform::MouseButton button) {
            return _pressedButtons.count(button);
        }

        static Vector2i getPosition() {
            return _mousePosition;
        }

        static void setPosition(const Vector2i &position) {
            _mousePosition = position;
        }

    private:
        static ::std::set<::MiniKit::Platform::MouseButton> _pressedButtons;
        static Vector2i _mousePosition;

    friend class GInputManager;
    };
}
