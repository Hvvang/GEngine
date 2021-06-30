#pragma once

#include <MiniKit/MiniKit.hpp>

namespace GEngine::Math {

    using ::MiniKit::Graphics::Color;

    struct GColor : Color {

        GColor &operator=(const Color &color) {
            red = color.red;
            green = color.green;
            blue = color.blue;
            alpha = color.alpha;
            return *this;
        }

        const float *Data() const noexcept {
            return &red;
        }

        float *Data() noexcept {
            return &red;
        }

        static const GColor BLACK;
        static const GColor GRAY;
        static const GColor WHITE;
        static const GColor RED;
        static const GColor GREEN;
        static const GColor BLUE;
        static const GColor CYAN;
        static const GColor MAGENTA;
        static const GColor YELLOW;

    };
}