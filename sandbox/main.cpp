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

        auto& graphicsDevice = context.GetGraphicsDevice();

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
        auto& commandBuffer = graphicsDevice.BeginFrame(1.0f, 1.0f, 1.0f, 1.0f);
        {
            commandBuffer.SetImage(*ubisoftLogoImage_);

            ::MiniKit::Graphics::DrawInfo drawDynamicLogo{};

            drawDynamicLogo.position = view.ViewportPointInDrawable(
                    Vector2f{ window.GetDrawableWidth() / 2.f, window.GetDrawableHeight() - ubisoftLogoImage_->GetSize().height / 2.f }
            );
            drawDynamicLogo.scale *= camera.GetZoom();
            drawDynamicLogo.tint.alpha = 1.f;

            commandBuffer.Draw(drawDynamicLogo);

            ::MiniKit::Graphics::DrawInfo drawStaticLogo{};
            drawStaticLogo.position = view.ViewportPointInDrawable(
                    Vector2f{ window.GetDrawableWidth() / 2.f - ubisoftLogoImage_->GetSize().width, window.GetDrawableHeight() - ubisoftLogoImage_->GetSize().height / 2.f }
            );
            drawStaticLogo.scale *= camera.GetZoom();
            drawStaticLogo.tint.alpha = 1.f;
            commandBuffer.Draw(drawStaticLogo);

        }
        graphicsDevice.EndFrame(commandBuffer);
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
