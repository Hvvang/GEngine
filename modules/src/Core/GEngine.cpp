#include <GEngine/Core/GEngine.hpp>
#include <GEngine/Input/GInputManager.hpp>
#include <GEngine/Event/GEventSystem.hpp>
#include <GEngine/Graphics/GRenderer.hpp>

using namespace GEngine::Event;
using namespace GEngine::Input;
using namespace GEngine::Graphics;

namespace GEngine::Core {
    ::MiniKit::Engine::StartupInfo Engine::_startupInfo{};
    ::MiniKit::Engine::Context *Engine::Context = { nullptr };
    GInputManager Engine::InputManager = GInputManager{};
    GEventSystem Engine::EventManager = GEventSystem{};
    GRenderer *Engine::Renderer = { nullptr };
    GWindow *Engine::Window = { nullptr };

    void Engine::InitWindow(const std::string &title, const uint32_t width, const uint32_t height, const bool VSync) {
        _startupInfo.window.width = width;
        _startupInfo.window.height = height;
        _startupInfo.window.title = title.c_str();
        _startupInfo.enableVSync = VSync;
    }
}
