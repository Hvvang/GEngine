#pragma once
#include <MiniKit/MiniKit.hpp>
#include <GEngine/Core/GWindow.hpp>
#include <GEngine/Input/GInputManager.hpp>
#include <GEngine/Graphics/GRenderer.hpp>

namespace GEngine::Core {

    class GApplication : public ::MiniKit::Engine::Application {
    public:
        virtual ::std::error_code Start(::MiniKit::Engine::Context &context) noexcept {
            auto &window = context.GetWindow();
            window.AddResponder(Engine::InputManager);

            Engine::Context = &context;
            Engine::Window = new GWindow(&context);
            Engine::Renderer = new ::GEngine::Graphics::GRenderer;
            return {};
        }
        virtual ::std::error_code Shutdown(::MiniKit::Engine::Context &context) noexcept {
            auto &window = context.GetWindow();
            window.RemoveResponder(Engine::InputManager);

            delete Engine::Window;
            delete Engine::Renderer;
            return {};
        }
        virtual void Tick(::MiniKit::Engine::Context &context) noexcept = 0;
    };
}
