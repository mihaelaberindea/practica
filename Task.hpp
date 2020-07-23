#ifndef TASK_HPP
#define TASK_HPP
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
class Task
{ 
 public:
   function<TaskResult(TaskArgument)> Task(int64_t prio,function<TaskResult(TaskArgument)> func);
   TaskResult operator()(TaskArgument);
   bool operator<(const Task& rhs);
   int64_t getPriority();
 private:
    function<TaskResult(TaskArgument)> m_function;
    int64_t m_priority;
};
#include "Task.tpp"
#endif 