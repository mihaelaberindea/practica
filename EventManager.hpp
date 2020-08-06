#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP
#include "EventPayload.hpp"
#include "EventType.hpp"
#include "Vector.hpp"
#include <functional>
#include <iostream>

class EventManager
{
  public:
    void subscribe(EventType eventType, THandler handler)
    {
        if(!m_handlers.contains(eventType) 
        {
            m_handlers[eventType] = {};
        }

        m_handlers[eventType].push_back(handler);
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
    map<EventType, vector<THandler>> m_handlers;
};
#endif