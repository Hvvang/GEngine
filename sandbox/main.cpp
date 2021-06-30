#include <MiniKit/MiniKit.hpp>

#include <GEngine/Core/GEngine.hpp>
#include <GEngine/Core/GApplication.hpp>
#include <GEngine/Core/GWindow.hpp>
#include <GEngine/Event/GEventSystem.hpp>

#include <GEngine/View/GViewport.hpp>

#include <GEngine/Input/GKeyboard.hpp>

#include <GEngine/Graphics/GSprite.hpp>
#include <GEngine/Graphics/GRenderer.hpp>

#include <iostream>

using namespace GEngine::Core;
using namespace GEngine::View;
using namespace GEngine::Input;

class Sandbox final : public GApplication {
public:

    Sandbox() {
        Engine::EventManager.connect(this, &Sandbox::onMouseEvent);
        Engine::EventManager.connect(this, &Sandbox::onKeyboardEvent);
    }

    ::std::error_code Start(::MiniKit::Engine::Context &context) noexcept override {
        GApplication::Start(context);

        auto& graphicsDevice = context.GetGraphicsDevice();

        ubisoftLogoImage_ = graphicsDevice.CreateImage("assets/images/ubisoft_logo.png");
        if (!ubisoftLogoImage_)
        {
            return ::MiniKit::MakeErrorCode(::MiniKit::Error::InitializationFailed);
        }

        view.SetRect({
            0.f, 0.f,
            float(context.GetWindow().GetDrawableWidth()), float(context.GetWindow().GetDrawableHeight())
        });
        auto &mainCamera = view.AddCamera();
//        mainCamera.SetPosition(Vector2f{ context.GetWindow().GetDrawableWidth() / 2.f, context.GetWindow().GetDrawableHeight() / 2.f });

        return ::MiniKit::MakeErrorCode(::MiniKit::Error::None);
    }

    void Tick(::MiniKit::Engine::Context &context) noexcept override {
        ::std::string title = "Frame: " + ::std::to_string(context.GetFrameCount()) + ", FPS: " + ::std::to_string(1.0f / context.GetFrameDelta());

        auto& window = context.GetWindow();
        window.SetTitle(title.c_str());

        // Camera Update
        auto &camera = view.AddCamera();
        {
            if (::GEngine::Input::GKeyboard::isKeyPressed(MiniKit::Platform::Keycode::KeyLeft)) {
                camera.Move(Vector2f::LEFT);
            }
            if (::GEngine::Input::GKeyboard::isKeyPressed(MiniKit::Platform::Keycode::KeyRight)) {
                camera.Move(Vector2f::RIGHT);
            }
            if (::GEngine::Input::GKeyboard::isKeyPressed(MiniKit::Platform::Keycode::KeyDown)) {
                camera.Move(Vector2f::DOWN);
            }
            if (::GEngine::Input::GKeyboard::isKeyPressed(MiniKit::Platform::Keycode::KeyUp)) {
                camera.Move(Vector2f::UP);
            }

            if (::GEngine::Input::GKeyboard::isKeyPressed(MiniKit::Platform::Keycode::KeyEqual)) {
                camera.ZoomIn();
            }
            if (::GEngine::Input::GKeyboard::isKeyPressed(MiniKit::Platform::Keycode::KeyMinus)) {
                camera.ZoomOut();
            }
            if (::GEngine::Input::GKeyboard::isKeyPressed(MiniKit::Platform::Keycode::Key0)) {
                camera.SetZoom(1.f);
            }
        }

        // Rendering
        Engine::Renderer->BeginRender(GColor::WHITE);
        {
            ::GEngine::Graphics::GSprite ubisoftSprite;

            ubisoftSprite._sprite = ubisoftLogoImage_.get();
            ubisoftSprite.GetTransform().SetPosition({0.f, 0.f});
            ubisoftSprite.GetTransform().SetScale({1.f, 1.f});

            Engine::Renderer->DrawSprite(ubisoftSprite);

        }
        Engine::Renderer->EndRender();
    }

    void onMouseEvent(GMouseEvent *event) {
        ::std::clog << "Mouse Event occurred with event type = " << event->type << ::std::endl;
    }

    void onKeyboardEvent(GKeyboardEvent *event) {
        ::std::clog << "Keyboard Event occurred with event type = " << event->type << ::std::endl;
    }

private:
    ::std::unique_ptr<::MiniKit::Graphics::Image> ubisoftLogoImage_{ nullptr };

    GViewport view;
};

int main(int argc, char** argv) {
    Engine::InitWindow("Sandbox", 800, 600);

    Sandbox sandbox{};

    return ::MiniKit::ApplicationMain(Engine::_startupInfo, sandbox);
}
