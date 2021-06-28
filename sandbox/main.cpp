#include <MiniKit/MiniKit.hpp>

#include <GEngine/Core/GEngine.hpp>
#include <GEngine/Core/GApplication.hpp>
#include <GEngine/Core/GWindow.hpp>
#include <GEngine/Event/GEventSystem.hpp>

#include <GEngine/View/GViewport.hpp>

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
            context.GetWindow().GetDrawableWidth() / 2.f,
            context.GetWindow().GetDrawableHeight() / 2.f,
            context.GetWindow().GetDrawableWidth() / 2.f,
            context.GetWindow().GetDrawableHeight() / 2.f
        });

        return ::MiniKit::MakeErrorCode(::MiniKit::Error::None);
    }

    void Tick(::MiniKit::Engine::Context &context) noexcept override {
        ::std::string title = "Frame: " + ::std::to_string(context.GetFrameCount()) + ", FPS: " + ::std::to_string(1.0f / context.GetFrameDelta());

        auto& window = context.GetWindow();
        window.SetTitle(title.c_str());

        auto& graphicsDevice = context.GetGraphicsDevice();

        // Rendering
        auto& commandBuffer = graphicsDevice.BeginFrame(1.0f, 1.0f, 1.0f, 1.0f);
        {
            commandBuffer.SetImage(*ubisoftLogoImage_);

            ::MiniKit::Graphics::DrawInfo drawStaticLogo{};

            drawStaticLogo.position = Engine::Window->RealPointInDrawable(view.GetRect().getPosition());

            ::std::clog << "Position : " << drawStaticLogo.position << ::std::endl;

            drawStaticLogo.scale = { 1.f, 1.f };
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
