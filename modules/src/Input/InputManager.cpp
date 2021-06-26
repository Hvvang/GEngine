#include "GEngine/Input/InputManager.hpp"

#include <GEngine/Input/Mouse.hpp>
#include <GEngine/Input/Keyboard.hpp>

namespace GEngine::Input {
    void InputManager::KeyDown(Window &window, const KeyEvent &event) noexcept {
        Keyboard::_pressedKeys.insert(event.keycode);
    }

    void InputManager::KeyUp(Window &window, const KeyEvent &event) noexcept {
        Keyboard::_pressedKeys.erase(event.keycode);
    }

    void InputManager::MouseDown(Window &window, const MouseEvent &event) noexcept {
        Mouse::_pressedButtons.insert(event.button);
    }

    void InputManager::MouseUp(Window &window, const MouseEvent &event) noexcept {
        Mouse::_pressedButtons.erase(event.button);
    }

    void InputManager::MouseMoved(Window &window, const MouseEvent &event) noexcept {
        Mouse::_mousePosition = {event.x, event.y};
    }
}

