#ifndef TASK_HPP
#define TASK_HPP
#include <cstdint>
#include <ostream>
#include <functional>

#include "TaskArgument.hpp"
#include "TaskResult.hpp"
class Task
{ 
 public:
   Task(int64_t prio,function<TaskResult(TaskArgument)> func);
   TaskResult operator()(TaskArgument);
   bool operator<(const Task& rhs);
   int64_t getPriority();
 private:
    function<TaskResult(TaskArgument)> m_function;
    int64_t m_priority;
};
#include "Task.tpp"
#endif 