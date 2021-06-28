#pragma once

#include <GEngine/Core/GObject.hpp>
#include <GEngine/Math/GVector.hpp>

using namespace GEngine::Math;

namespace GEngine::Core {

    class GWindow final : public GObject  {
    public:
        explicit GWindow(::MiniKit::Engine::Context *context) : GObject(context) {
            _name = "Window";
        }

        template<class T>
        Vector2f RealPointInDrawable(const T &point) {
            const auto drawableWidth = _context->GetWindow().GetDrawableWidth();
            const auto drawableHeight = _context->GetWindow().GetDrawableHeight();

            return {point.x - drawableWidth / 2.f, -(point.y - drawableHeight / 2.f)};
        }

        template<class T>
        Vector2f DrawablePointInReal(const T &point) {
            const auto drawableWidth = _context->GetWindow().GetDrawableWidth();
            const auto drawableHeight = _context->GetWindow().GetDrawableHeight();

            return {point.x + drawableWidth / 2.f, -(point.y - drawableHeight / 2.f)};
        }
    };


}