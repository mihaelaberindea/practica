#ifndef TASK_HPP
#define TASK_HPP
#include <cstdint>
#include <functional>
#include <ostream>

#include "TaskArgument.hpp"
#include "TaskResult.hpp"
class Task
{
  public:
    Task(int64_t prio, function<TaskResult(TaskArgument)> func);
    TaskResult operator()();
    bool operator<(const Task& rhs);
    int64_t getPriority();
    std::function<TaskResult()> get_m_function();

  private:
    function<TaskResult(TaskArgument)> m_function;
    int64_t m_priority;
};
#include "Task.tpp"
#endif