#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP
#include "EventPayload.hpp"
#include "EventType.hpp"
#include "Vector.hpp"
#include <cstddef>
#include <functional>
#include <map>

class EventManager
{
  public:
    void subscribe(EventType eventType, THandler handler)
    {
        if(!m_handlers.contains(eventType))
        {
            m_handlers[eventType] = {};
        }

        m_handlers[eventType].pushBack(handler);
    }
    void fire(EventType eventType, EventPayload payload)
    {
        for (auto& handler : m_handlers[eventType])
        {
            handler(payload);
        }
    }

  private:
    std::function<void(const EventPayload&)> THandler;
    std::map <EventType, Vector<THandler>> m_handlers;
};
#endif