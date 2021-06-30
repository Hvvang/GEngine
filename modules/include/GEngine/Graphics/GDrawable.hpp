#pragma once

#include <MiniKit/MiniKit.hpp>
#include <entityx/entityx.h>
#include <GEngine/Math/GColor.hpp>
#include <GEngine/Math/GRect.hpp>

namespace GEngine::Graphics {

    struct GDrawable : entityx::Component<GDrawable> {
    protected:
        virtual void draw(::MiniKit::Graphics::CommandBuffer &commandBuffer) = 0;

        ::MiniKit::Graphics::Image *_sprite {nullptr};
        ::GEngine::Math::GColor _spriteColor = ::GEngine::Math::GColor::BLACK;
        ::GEngine::Math::UIntRect _tileRect = ::GEngine::Math::UIntRect::INF;
    };
}