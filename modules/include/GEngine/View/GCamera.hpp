#pragma once

#include <GEngine/Core/GObject.hpp>
#include <GEngine/Core/GEngine.hpp>
#include <GEngine/Math/GVector.hpp>
#include <GEngine/Event/GEventSystem.hpp>
#include <GEngine/Input/GInputManager.hpp>

using namespace GEngine::Core;
using namespace GEngine::Math;

namespace GEngine::View {

    class GCamera : public GObject {
    public:
        GCamera() : GObject(Engine::Context) {
            _name = "Camera";
        }

        float GetZoom() const noexcept {
            return _zoom;
        }

        const Vector2f &GetPosition() const noexcept {
           return _position;
        }

        void SetZoom(float zoom) {
            _zoom = zoom;
        }

        void SetPosition(const Vector2f &position) {
            _position = position;
        }

        void Move(const Vector2f &offset) {
            _position += offset * _moveSpeed;
        }

        void ZoomIn() {
            _zoom += _zoomSpeed;
        }

        void ZoomOut() {
            _zoom -= _zoomSpeed;
        }

    private:
        float _zoom = 1.f;
        float _moveSpeed = 10.f;
        float _zoomSpeed = 0.01f;
        Vector2f _position = Vector2f::ZERO;
    };
}
