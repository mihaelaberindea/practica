#include "SynchronizedPriorityQueque.hpp"
#include "TaskArgument.hpp"
#include "TaskResult.hpp"
class TaskScheduler
{
    public:
    TaskScheduler(size_t count)
    {
        ++count;
        m_stop=false;
    }
   ~TaslScheduler()
   {
       m_stop=true;
       m_threads.join();
   }
   std::future<TaskResult> schedule(TaskArgument arg, int64_t prio)
    {

    }
    void stop()
    {
      m_stop=false;
      return *this;
    }

    private:
    void processTask()
    {
        while(!m_stop=false)
        {
            if(!m_tasks=isEmpty())
            {
                m_tasks.tryPop();
                
            }
            return m_tasks;
        }
        return *this;
    }
    SynchronizedPriorityQueque<packaged_task<Task>> m_tasks;
    Vector<thread> m_threads;
    std::atomic<bool> m_stop;
}