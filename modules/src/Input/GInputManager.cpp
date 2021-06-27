#include "GEngine/Input/GInputManager.hpp"

#include <GEngine/Input/GMouse.hpp>
#include <GEngine/Input/GKeyboard.hpp>

namespace GEngine::Input {
    void GInputManager::KeyDown(Window &window, const KeyEvent &event) noexcept {
        GKeyboard::_pressedKeys.insert(event.keycode);
    }

    void GInputManager::KeyUp(Window &window, const KeyEvent &event) noexcept {
        GKeyboard::_pressedKeys.erase(event.keycode);
    }

    void GInputManager::MouseDown(Window &window, const MouseEvent &event) noexcept {
        GMouse::_pressedButtons.insert(event.button);
    }

    void GInputManager::MouseUp(Window &window, const MouseEvent &event) noexcept {
        GMouse::_pressedButtons.erase(event.button);
    }

    void GInputManager::MouseMoved(Window &window, const MouseEvent &event) noexcept {
        GMouse::_mousePosition = { event.x, event.y };
    }
}

