#pragma once

#include <MiniKit/MiniKit.hpp>

namespace GEngine::Input {
    class GInputManager;
}

namespace GEngine::Event {
    class GEventSystem;
}

using namespace GEngine::Event;
using namespace GEngine::Input;

namespace GEngine::Core {

    class GApplication;

    class Engine {
    public:

        static ::MiniKit::Engine::StartupInfo _startupInfo;
        static GEventSystem EventManager;
        static ::GEngine::Input::GInputManager InputManager;

        static void InitWindow(const ::std::string &title, uint32_t width, uint32_t height, bool VSync = false);

    };


}
