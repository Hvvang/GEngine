#include <MiniKit/MiniKit.hpp>

#include <GEngine/Core/GEngine.hpp>
#include <GEngine/Core/GApplication.hpp>
#include <GEngine/Event/GEventSystem.hpp>

#include <iostream>

using namespace GEngine::Core;

class Sandbox final : public GApplication {
public:

    Sandbox() {
        Engine::EventManager.connect(this, &Sandbox::onMouseEvent);
        Engine::EventManager.connect(this, &Sandbox::onKeyboardEvent);
    }

    void GameLoop(::MiniKit::Engine::Context &context) noexcept override {
        ::std::string title = "Frame: " + ::std::to_string(context.GetFrameCount()) + ", FPS: " + ::std::to_string(1.0f / context.GetFrameDelta());

        auto& window = context.GetWindow();
        window.SetTitle(title.c_str());
    }

    void onMouseEvent(GMouseEvent *event) {
        ::std::clog << "Mouse Event occurred with event type = " << event->type << ::std::endl;
    }

    void onKeyboardEvent(GKeyboardEvent *event) {
        ::std::clog << "Keyboard Event occurred with event type = " << event->type << ::std::endl;
    }
};

int main(int argc, char** argv) {
    Engine::InitWindow("Sandbox", 800, 600);

    Sandbox sandbox{};

    return ::MiniKit::ApplicationMain(Engine::_startupInfo, sandbox);
}
