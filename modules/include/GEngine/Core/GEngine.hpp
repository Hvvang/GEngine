#pragma once

#include <MiniKit/MiniKit.hpp>

namespace GEngine::Input {
    class GInputManager;
}

namespace GEngine::Event {
    class GEventSystem;
}

namespace GEngine::Graphics {
    class GRenderer;
}

namespace GEngine::Core {

    class GApplication;
    class GWindow;

    class Engine {
    public:

        static ::MiniKit::Engine::StartupInfo _startupInfo;
        static ::MiniKit::Engine::Context *Context;
        static ::GEngine::Event::GEventSystem EventManager;
        static ::GEngine::Input::GInputManager InputManager;
        static ::GEngine::Core::GWindow *Window;
        static ::GEngine::Graphics::GRenderer *Renderer;

        static void InitWindow(const ::std::string &title, uint32_t width, uint32_t height, bool VSync = false);

    };


}
