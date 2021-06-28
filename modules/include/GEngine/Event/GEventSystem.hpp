#pragma once

#include <list>
#include <map>
#include <typeindex>

#include <GEngine/Event/GBaseHandler.hpp>
#include <GEngine/Event/GHandler.hpp>

namespace GEngine::Event {

    typedef std::list<GBaseHandler *> HandlerList;

    class GEventSystem {
    public:
        template<typename EventType>
        void emit(EventType *event) {
            HandlerList *handlers = subscribers[typeid(EventType)];

            if (!handlers)
                return;

            for (auto &handler : *handlers) {
                if (handler)
                    handler->exec(event);
            }
            delete event;
        }

        template<class T, class EventType>
        void connect(T *instance, void (T::*member)(EventType *)) {
            HandlerList *handlers = subscribers[typeid(EventType)];

            //First time initialization
            if (!handlers) {
                handlers = new HandlerList();
                subscribers[typeid(EventType)] = handlers;
            }

            handlers->push_back(new GHandler<T, EventType>(instance, member));
        }

    private:
        std::map<std::type_index, HandlerList *> subscribers;
    };
}