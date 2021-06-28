#pragma once

namespace GEngine::Event {
    class GEvent;

    class GBaseHandler {
    public:
        virtual ~GBaseHandler() {};
        void exec(GEvent *event) {
            call(event);
        }

    private:
        virtual void call(GEvent *) = 0;
    };
}

