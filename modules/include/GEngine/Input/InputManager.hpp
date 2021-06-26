#pragma once

#include <MiniKit/MiniKit.hpp>

using namespace ::MiniKit::Platform;

namespace GEngine::Input {
    class InputManager : public ::MiniKit::Platform::Responder {
        void KeyDown(Window &window, const KeyEvent &event) noexcept override;
        void KeyUp(Window &window, const KeyEvent &event) noexcept override;
        void MouseDown(Window &window, const MouseEvent &event) noexcept override;
        void MouseUp(Window &window, const MouseEvent &event) noexcept override;
        void MouseMoved(Window &window, const MouseEvent &event) noexcept override;
    };
}


