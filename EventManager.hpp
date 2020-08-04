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
    void subscribe(EventType type, THandler handler)
    {
        if(!m_handlers.contains(type) 
        {
            m_handlers[type] = {};
        }

        m_handlers[type].push_back(handler);
    }
    void fire(EventType type, EventPayload payload)
    {
        for (auto& handler : m_handlers[type])
        {
            handler(payload);
        }
    }

  private:
    std::function<void(const EventPayload&)> THandler;
    map<EventType, vector<THandler>> m_handlers;
};
#endif