#pragma once

#include <MiniKit/MiniKit.hpp>

#include <GEngine/Core/GEngine.hpp>
#include <GEngine/Core/GObject.hpp>
#include <GEngine/Graphics/GSprite.hpp>

using namespace GEngine::Core;
using namespace MiniKit::Graphics;

namespace GEngine::Graphics {

    class GRenderer final : public GObject {
    public:
        GRenderer() : GObject(Engine::Context) {
            _name = "Renderer";
        }

        void BeginRender(const GColor &color) {
            if (_commandBuffer) {
                throw ::std::runtime_error("GRenderer::EndRender was not called before.");
            }
            auto &graphicDevice = _context->GetGraphicsDevice();

            _commandBuffer = &graphicDevice.BeginFrame(color.red, color.green, color.blue, color.alpha);
        }

        void EndRender() {
            if (!_commandBuffer) {
                throw ::std::runtime_error("GRenderer::BeginRender was not called before.");
            }
            auto &graphicDevice = _context->GetGraphicsDevice();
            graphicDevice.EndFrame(*_commandBuffer);
            _commandBuffer = nullptr;
        }

        void DrawSprite(const GSprite &sprite) {
            if (!_commandBuffer) {
                throw ::std::runtime_error("GRenderer::BeginRender was not called before.");
            }
            sprite.draw();
        }

    private:
        CommandBuffer *_commandBuffer{ nullptr };

    };

}