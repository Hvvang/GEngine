#pragma once

#include <GEngine/Core/GObject.hpp>
#include <GEngine/View/GCamera.hpp>
#include <GEngine/Core/GEngine.hpp>
#include <GEngine/Core/GWindow.hpp>
#include <GEngine/Math/GVector.hpp>
#include <GEngine/Math/GRect.hpp>

using namespace GEngine::Core;
using namespace GEngine::Math;

namespace GEngine::View {

    class GCamera;

    class GViewport : public GObject {
    public:
        GViewport();

        explicit GViewport(const FloatRect &rect);

        explicit GViewport(const GViewport &viewport);

        void SetRect(const FloatRect &rect);

        void SetPosition(const Vector2f &position);

        void SetSize(const Vector2f &size);

        const FloatRect &GetRect() const noexcept;

        GCamera &AddCamera() {
            if (!_camera)
                _camera = ::std::make_unique<GCamera>();
            return *_camera;
        }

        template<class T>
        Vector2f WorldPointInViewport(const T &point) {
            if (!_camera) {
                return point - _representation.getPosition();
            }
            return point + _camera->GetPosition() - _representation.getPosition();
        }

        template<class T>
        Vector2f ViewportPointInWorld(const T &point) {
            if (!_camera) {
                return _representation.getPosition() + point;
            }
            return (_representation.getPosition() - Vector2f {_camera->GetPosition().x, -_camera->GetPosition().y} + point) * _camera->GetZoom();
        }

        template<class T>
        Vector2f ViewportPointInDrawable(const T &point) {
            return Engine::Window->template RealPointInDrawable(ViewportPointInWorld(point));
        }

        template<class T>
        Vector2f DrawablePointInViewport(const T &point) {
            return RealPointInDrawable(Engine::Window->template DrawablePointInReal(point));
        }

    private:
        ::std::unique_ptr<GCamera> _camera{ nullptr };
        FloatRect _representation = FloatRect::ZERO;

    };

}



