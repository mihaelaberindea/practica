#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP
#include "EventPayload.hpp"
#include "EventType.hpp"
#include "Vector.hpp"
#include <functional>
class EventManager
{
  public:
    void subscribe(EventType type, THandler handler);
    void fire(EventType type, EventPayload payload);

  private:
    std::function<void(const EventPayload&)> THandler;
    map<EventType, vector<THandler>> m_handlers;
};
#endif