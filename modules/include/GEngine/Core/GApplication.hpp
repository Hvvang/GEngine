#pragma once

#include <GEngine/Input/GInputManager.hpp>

namespace GEngine::Core {

    class GApplication : public ::MiniKit::Engine::Application {
    private:
        ::std::error_code Start(::MiniKit::Engine::Context &context) noexcept override {
            auto &window = context.GetWindow();
            window.AddResponder(Engine::InputManager);
            return {};
        }
        ::std::error_code Shutdown(::MiniKit::Engine::Context &context) noexcept override {
            auto &window = context.GetWindow();
            window.RemoveResponder(Engine::InputManager);
            return {};
        }
        void Tick(::MiniKit::Engine::Context &context) noexcept override {
            GameLoop(context);
        }
    public:
        virtual void GameLoop(::MiniKit::Engine::Context &context) noexcept = 0;
    };
}
