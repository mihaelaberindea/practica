#ifndef TASK_HPP
#define TASK_HPP
#include <future>
#include <string>
#include <cstddef>
#include <ostream>

#include "TaskArgument.hpp"
#include "TaskResult.hpp"
#include "Function.hpp"
class Task
{
  public:
    Task();
    Task(int64_t prio, std::packaged_task<TaskResult()> &&func);
    void operator()();
    bool operator<(const Task& rhs);
    std::int64_t getPriority();
    std::function<TaskResult()> get_m_function();
    friend std::ostream &operator<<(std::ostream &os, const Task &task);
  private:
    function<void()> m_function;
    int64_t m_priority;
};
#include "Task.tpp"
#endif