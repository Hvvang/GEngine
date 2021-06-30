#pragma once

#include <GEngine/Math/GVector.hpp>
#include <GEngine/Graphics/GTransform.hpp>

using namespace GEngine::Math;

namespace GEngine::Graphics {

    struct GTransformable : entityx::Component<GTransformable> {

        GTransform &rotate(float angle) noexcept {
            _transform._angle += angle;
            return _transform;
        }

        GTransform &move(const Vector2f &offset) noexcept {
            _transform._position += offset;
            return _transform;
        }

        GTransform &zoom(const Vector2f &offset) noexcept {
            _transform._scale += offset;
            return _transform;
        }

        GTransform &GetTransform() noexcept {
            return _transform;
        };

    protected:
        GTransform _transform{};
    };

}