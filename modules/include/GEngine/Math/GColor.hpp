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

    std::ostream& operator<<(std::ostream& out, const Color &color) {
        out << "GColor(" << color.red << ", " << color.green << ", " << color.blue << ", " << color.alpha << ");";
        return out;
    }

    const GColor GColor::BLACK{ 0.f, 0.f, 0.f, 1.f };
    const GColor GColor::WHITE{ 0.f, 0.f, 0.f, 1.f };
    const GColor GColor::RED{ 1.f, 0.f, 0.f, 1.f };
    const GColor GColor::GREEN{ 0.f, 1.f, 0.f, 1.f };
    const GColor GColor::BLUE{ 0.f, 0.f, 1.f, 1.f };
    const GColor GColor::GRAY{ 0.5, 0.5, 0.5, 1.f };
    const GColor GColor::CYAN{ 0.f, 1.f, 1.f, 1.f };
    const GColor GColor::MAGENTA{ 1.f, 0.f, 1.f, 1.f };
    const GColor GColor::YELLOW{ 1.f, 1.f, 0.f, 1.f };
}