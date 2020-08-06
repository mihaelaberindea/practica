#include "SynchronizedPriorityQueue.hpp"
#include "Task.hpp"
#include "TaskScheduler.hpp"
#include <functional>
#include <future>
#include <iostream>
#include <thread>

TaskScheduler::TaskScheduler(std::size_t count)
{
    m_stop = false;

    for (std::size_t idx = 0; idx < count; ++idx)
    {
        m_threads.pushBack(std::thread(&TaskScheduler::processTasks, this));
    }
    // std::cout<< "TaskScheduler ctr"<< std::endl;
}

TaskScheduler::~TaskScheduler()
{
    m_stop = true;

    for (std::size_t idx = 0; idx < m_threads.getSize(); ++idx)
    {
        m_threads[idx].join();
    }
    // /std::cout<< "TaskScheduler dtr"<< std::endl;
}

std::future<TaskResult> TaskScheduler::schedule(TaskArgument arg, std::int64_t prio)
{

    auto lambda = [arg]() {
        TaskResult tr;
        tr.sum = arg.a + arg.b;
        return tr;
    };

    std::packaged_task<TaskResult()> packedTask(lambda);

    std::future<TaskResult> futureTask = packedTask.get_future();

    Task task(prio, std::move(packedTask));

    m_tasks.push(std::move(task));

    return futureTask;
}

void TaskScheduler::stop() { m_stop = true; }