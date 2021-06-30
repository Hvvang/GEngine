#include <GEngine/Math/GVector.hpp>
#include <GEngine/Math/GRect.hpp>
#include <GEngine/Math/GColor.hpp>

namespace GEngine::Math {

    /// GColor predef
    const GColor GColor::BLACK{ 0.f, 0.f, 0.f, 1.f };
    const GColor GColor::WHITE{ 1.f, 1.f, 1.f, 1.f };
    const GColor GColor::RED{ 1.f, 0.f, 0.f, 1.f };
    const GColor GColor::GREEN{ 0.f, 1.f, 0.f, 1.f };
    const GColor GColor::BLUE{ 0.f, 0.f, 1.f, 1.f };
    const GColor GColor::GRAY{ 0.5, 0.5, 0.5, 1.f };
    const GColor GColor::CYAN{ 0.f, 1.f, 1.f, 1.f };
    const GColor GColor::MAGENTA{ 1.f, 0.f, 1.f, 1.f };
    const GColor GColor::YELLOW{ 1.f, 1.f, 0.f, 1.f };

    std::ostream &operator<<(std::ostream& out, const Color &color) {
        out << "GColor(" << color.red << ", " << color.green << ", " << color.blue << ", " << color.alpha << ");";
        return out;
    }

}