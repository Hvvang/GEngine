#pragma once

#include <MiniKit/MiniKit.hpp>
#include <GEngine/Event/GEvent.hpp>
#include <GEngine/Math/GVector.hpp>

using namespace ::MiniKit::Platform;
using namespace ::GEngine::Event;
using namespace ::GEngine::Math;

namespace GEngine::Core {
    class Engine;
}

namespace GEngine::Input {

    struct GMouseEvent : GEvent {
        GMouseEvent(GEvent::Type type, const Vector2i &_position, MouseButton _pressedButton)
            : GEvent(type)
            , position(_position)
            , pressedButton(_pressedButton) {}

        Vector2i position;
        MouseButton pressedButton;
    };

    struct GKeyboardEvent : GEvent {
        GKeyboardEvent(GEvent::Type type, Keycode _pressedButton)
                : GEvent(type)
                , pressedButton(_pressedButton) {}

        Keycode pressedButton;
    };

    class GInputManager : public ::MiniKit::Platform::Responder {
        void KeyDown(Window &window, const KeyEvent &event) noexcept override;
        void KeyUp(Window &window, const KeyEvent &event) noexcept override;
        void MouseDown(Window &window, const MouseEvent &event) noexcept override;
        void MouseUp(Window &window, const MouseEvent &event) noexcept override;
        void MouseMoved(Window &window, const MouseEvent &event) noexcept override;
    };
}


