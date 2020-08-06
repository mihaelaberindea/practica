#ifndef TASK_HPP
#define TASK_HPP

#include <cstdint>
#include <future>
#include <ostream>

#include "Function.hpp"
#include "TaskArgument.hpp"
#include "TaskResult.hpp"

class Task
{
  public:
    Task() = default;

    Task(std::int64_t prio, std::packaged_task<TaskResult()>&& func);

    void operator()();
    bool operator<(const Task& rhs);

    friend std::ostream& operator<<(std::ostream& os, const Task& t);
    std::int64_t getPriority();

  private:
    std::int64_t m_priority;
    Function<void()> m_function;
};
#include "Task.tpp"
#endif // TASK_HPP