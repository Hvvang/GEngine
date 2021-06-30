#pragma once

#include <entityx/entityx.h>

namespace GEngine::Graphics {

    struct GTransform {

        void SetOrigin(const Vector2f &origin) noexcept { _origin = origin; }

        void SetPosition(const Vector2f &origin) noexcept { _origin = origin; }

        void SetScale(const Vector2f &scale) noexcept { _scale = scale; }

        void SetAngle(float angle) { _angle = angle; }

        Vector2f GetOrigin() const noexcept { return _origin; }
        Vector2f GetPosition() const noexcept { return _position; }
        Vector2f GetScale() const noexcept { return _scale; }
        float GetAngle() const noexcept { return _angle; }

    protected:
        Vector2f _origin;
        Vector2f _position;
        Vector2f _scale;
        float _angle;

    friend struct GTransformable;
    };
}