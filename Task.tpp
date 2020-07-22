#include "Task.hpp" 
#include "TaskArgument.hpp"
#include <iostream>

function<TaskResult(TaskArgument)> Task::Task(int64_t prio,function<TaskResult(TaskArgument)> func)
{

}
TaskResult Task::operator()(TaskArgument)
{
   m_function(TaskArgument);
   return TaskResult;
}
bool Task::operator<(const Task& rhs)
{
    return m_priority < rhs.m_priority;
}
