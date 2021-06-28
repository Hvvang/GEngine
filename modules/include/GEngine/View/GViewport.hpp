#pragma once

#include <GEngine/Core/GObject.hpp>
#include <GEngine/Core/GEngine.hpp>
#include <GEngine/Core/GWindow.hpp>
#include <GEngine/Math/GVector.hpp>
#include <GEngine/Math/GRect.hpp>

using namespace GEngine::Core;
using namespace GEngine::Math;

namespace GEngine::View {
    class GViewport : public GObject {
    public:
        GViewport();

        explicit GViewport(const FloatRect &rect);

        explicit GViewport(const GViewport &viewport);

        void SetRect(const FloatRect &rect);

        void SetPosition(const Vector2f &position);

        void SetSize(const Vector2f &size);

        const FloatRect &GetRect() const noexcept;

        template<class T>
        Vector2f RealPointInViewport(const T &point) {
            return point - _representation.getPosition();
        }

        template<class T>
        Vector2f ViewportPointInReal(const T &point) {
            return _representation.getPosition() + point;
        }

        template<class T>
        Vector2f ViewportPointInDrawable(const T &point) {
            return Engine::Window->template RealPointInDrawable(ViewportPointInReal(point));
        }

        template<class T>
        Vector2f DrawablePointInViewport(const T &point) {
            return RealPointInDrawable(Engine::Window->template DrawablePointInReal(point));
        }

    private:
        FloatRect _representation = FloatRect::ZERO;

    };

}



