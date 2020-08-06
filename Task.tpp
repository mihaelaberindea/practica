#include "Task.hpp"
#include <ostream>

Task::Task(int64_t prio, std::packaged_task<TaskResult()>&& func)
{
    m_priority = prio;
    m_function = std::move(func);
}

int64_t Task::getPriority() { return m_priority; }

bool Task::operator<(const Task& rhs)
{
    if (m_priority < rhs.m_priority)
    {
        return true;
    }
    return false;
}

void Task::operator()() { m_function(); }

std::ostream& operator<<(std::ostream& os, const Task& t)
{
    os << "priority: " << t.m_priority << "\n";

    return os;
}
