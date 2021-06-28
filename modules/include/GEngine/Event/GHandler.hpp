#pragma once

namespace GEngine::Event {

    class GBaseHandler;
    class GEvent;

    template<class T, class EventType>
    class GHandler : public GBaseHandler {
    public:
        typedef void (T::*Member)(EventType *);

        GHandler(T *instance, Member member) : _instance{instance}, _member{member} {};

        void call(GEvent *event) override {
            // Cast event to the correct type and call member function
            (_instance->*_member)(static_cast<EventType *>(event));
        }

    private:
        // Pointer to class instance
        T *_instance;

        // Pointer to member function
        Member _member;
    };
}