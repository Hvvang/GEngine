#include <GEngine/Input/GInputManager.hpp>
#include <GEngine/Core/GEngine.hpp>

#include <GEngine/Input/GMouse.hpp>
#include <GEngine/Input/GKeyboard.hpp>

#include "GEngine/Event/GEventSystem.hpp"

using namespace GEngine::Core;

namespace GEngine::Input {

    /// GMouse and GKeyboard fields property prededef
    ::std::set<::MiniKit::Platform::Keycode> GKeyboard::_pressedKeys{};
    ::std::set<::MiniKit::Platform::MouseButton> GMouse::_pressedButtons{};
    Vector2i GMouse::_mousePosition{};

    void GInputManager::KeyDown(Window &window, const KeyEvent &event) noexcept {
        if (!GKeyboard::_pressedKeys.count(event.keycode)) {
            GKeyboard::_pressedKeys.insert(event.keycode);

            Engine::EventManager.emit(
                    new GKeyboardEvent(Event::GEvent::KeyPress, event.keycode)
            );
        }
    }

    void GInputManager::KeyUp(Window &window, const KeyEvent &event) noexcept {
        if (GKeyboard::_pressedKeys.count(event.keycode)) {
            GKeyboard::_pressedKeys.erase(event.keycode);

            GEngine::Core::Engine::EventManager.emit(
                    new GKeyboardEvent(Event::GEvent::KeyRelease, event.keycode)
            );
        }
    }

    void GInputManager::MouseDown(Window &window, const MouseEvent &event) noexcept {
        if (!GMouse::_pressedButtons.count(event.button)) {
            GMouse::_pressedButtons.insert(event.button);

            GEngine::Core::Engine::EventManager.emit(
                    new GMouseEvent(Event::GEvent::MouseButtonPress, GMouse::_mousePosition, event.button)
            );
        }
    }

    void GInputManager::MouseUp(Window &window, const MouseEvent &event) noexcept {
        if (GMouse::_pressedButtons.count(event.button)) {
            GMouse::_pressedButtons.erase(event.button);

            GEngine::Core::Engine::EventManager.emit(
                    new GMouseEvent(Event::GEvent::MouseButtonRelease, GMouse::_mousePosition, event.button)
            );
        }
    }

    void GInputManager::MouseMoved(Window &window, const MouseEvent &event) noexcept {
        if (GMouse::_mousePosition != Vector2i{ event.x, event.y }) {
            GMouse::_mousePosition = { event.x, event.y };

            GEngine::Core::Engine::EventManager.emit(
                    new GMouseEvent(Event::GEvent::MouseMove, GMouse::_mousePosition, event.button)
            );
        }
    }
}

