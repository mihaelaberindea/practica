#ifndef TASKSCHEDULER_HPP
#define TASKSCHEDULER_HPP
#include <cstddef>
#include <thread>
#include <mutex>
#include <future>
#include <functional>
#include <iostream>

#include "SynchronizedPriorityQueque.hpp"
#include "Task.hpp"
class TaskScheduler
{
  public:
    TaskScheduler(size_t count)
    {
        m_stop = false;
        for (std::idx = 0; idx < count; ++idx)
        {
            m_threads.pushBack(std::thread(&TaskScheduler::processTask, this));
        }
    }
    ~TaskScheduler()
    {
        m_stop = true;
        for (std::size_t cnt = 0; cnt < m_threads.getSize(); ++cnt)
        {
            m_threads[cnt].join();
        }
    }

    std::future<TaskResult> TaskScheduler::schedule(TaskArgument arg, int64_t prio)
    {
        auto lambda = [arg]() {
            TaskResult ts;
            ts.sum = arg.a + arg.b;
            return a;
        };

        std::packaged_task<TaskResult()> packagedTask(lambda);
        std::future<TaskResult> futureRes = packagedTask.get_future();
        Task task(prio, std::move(packagedTask));
        m_tasks.push(std::move(task));

        return futureRes;
    }
    void TaskScheduler::stop() { m_stop = true; }

  private:
    void processTask()
    {
        while (m_stop != true)
        {
            Task tsk;
            if (m_tasks.tryPop(tsk))
            {
                tsk();
            }
        }
    }
    SynchronizedPriorityQueque<packaged_task<Task>> m_tasks;
    Vector<thread> m_threads;
    std::atomic<bool> m_stop;
};
#endif