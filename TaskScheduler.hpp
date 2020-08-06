#ifndef TASKSCHEDULER_HPP
#define TASKSCHEDULER_HPP
#include "SynchronizedPriorityQueue.hpp"
#include "Task.hpp"
#include "Vector.hpp"
#include <atomic>
#include <future>
#include <iostream>
#include <thread>

class TaskScheduler
{
  public:
    TaskScheduler(std::size_t count);
    ~TaskScheduler();

    std::future<TaskResult> schedule(TaskArgument arg, std::int64_t prio);
    void stop();

  private:
    SPriorityQueue<Task> m_tasks;
    Vector<std::thread> m_threads;
    std::atomic<bool> m_stop;

    void processTasks()
    {
        while (!m_stop)
        {
            Task popRez;
            if (m_tasks.tryPop(popRez))
            {
                popRez();
            }
        }
    }
};

#include "TaskScheduler.tpp"
#endif // TASKSCHEDULER_HPP