#pragma once

#include <MiniKit/Engine/Context.hpp>

namespace GEngine::Core {
    class GObject {
    public:
        GObject(::MiniKit::Engine::Context *context = nullptr) noexcept
            : _context(context) {};

        void SetName(const std::string &name) {
            _name = name;
        }

        const ::std::string &GetName() const noexcept { return _name; }

        ::std::string &GetName() noexcept { return _name; }

    protected:
        ::MiniKit::Engine::Context *_context;
        ::std::string _name;
    };

}
