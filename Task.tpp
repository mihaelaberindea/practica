#include "Task.hpp" 
#include <iostream>
#include <string.h>
#include <ostream>
Task::Task()
{
    m_description = NULL;
    m_priority = -1;
}
std::string getDescription()
{
    return m_description;
}
int8_t getPriority()
{
     return m_priority;
}
bool operator<(const Task& rhs)
{
    if(m_priority < rhs.m_priority)
    {
        return true;
    }
    return false;
}
 friend std::ostream&operator<<(std::ostream& os,const Task& task)
 {
      os << "description: " 
       << task.m_description << "\n";
      os << "priority: " 
       << task.m_priority << "\n";

    return os;
 }
