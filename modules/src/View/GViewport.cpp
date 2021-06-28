#include <GEngine/View/GViewport.hpp>

namespace GEngine::View {

    GViewport::GViewport() : GObject(Engine::Context) {
        _name = "Viewport";
    }

    GViewport::GViewport(const FloatRect &rect) : GViewport() {
        _representation = rect;
    }

    GViewport::GViewport(const GViewport &viewport) : GViewport() {
        _representation = viewport._representation;
    }

    void GViewport::SetRect(const FloatRect &rect) {
        _representation = rect;
    }

    void GViewport::SetPosition(const Vector2f &position) {
        _representation.setPosition(position);
    }

    void GViewport::SetSize(const Vector2f &size) {
        _representation.setSize(size);
    }

    const FloatRect &GViewport::GetRect() const noexcept {
        return _representation;
    }
}
