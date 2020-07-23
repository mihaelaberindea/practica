#include "Task.hpp"
#include "TaskArgument.hpp"
#include "TaskResult.hpp"
#include <ostream>

Task::Task(int64_t prio, std::function<TaskResult(TaskArgument)> func)
{
    m_priority = prio;
    m_function = func;
}
int64_t Task::getPriority() { return m_priority; }
TaskResult Task::operator()(TaskArgument arg) { return m_function(arg); }
bool Task::operator<(const Task& rhs)
{
    if (m_priority < rhs.m_priority)
    {
        return true;
    }
    return false;
}
