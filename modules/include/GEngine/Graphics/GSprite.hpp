#pragma once

#include <MiniKit/MiniKit.hpp>
#include <GEngine/Graphics/GDrawable.hpp>
#include <GEngine/Graphics/GTransformable.hpp>

namespace GEngine::Graphics {

    struct GSprite : GDrawable, GTransformable {
        void draw(::MiniKit::Graphics::CommandBuffer &commandBuffer) const override {
            commandBuffer.SetImage(*_sprite);
            ::MiniKit::Graphics::DrawInfo info = {
                    _spriteColor,
                    _transform.GetPosition(),
                    _transform.GetScale(),
                    _transform.GetAngle(),
            };

            if (_tileRect == UIntRect::INF) {
                commandBuffer.Draw(info);
            } else {
                commandBuffer.Draw(info, _tileRect);
            }
        }
    };
}