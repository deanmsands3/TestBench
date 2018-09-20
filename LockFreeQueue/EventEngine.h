#ifndef EVENTENGINE_H
#define EVENTENGINE_H
#include "Event.h"
#include <boost/lockfree/queue.hpp>
#include <thread>
#include <condition_variable>
#include <mutex>

namespace DMS3{

class EventEngine
{
    boost::lockfree::queue<Event> _queue;
    std::mutex                  _lockqueue;
    std::condition_variable     _queuecheck;
    const unsigned _size_of_queue;
    const unsigned short _engine_id;
    bool _done;
protected:
    virtual void process_events();
    virtual void process_event(Event &ev);
public:
    EventEngine();
    EventEngine(const unsigned new_size_of_queue, const unsigned short new_engine_id);
    EventEngine(const EventEngine& that);
    virtual ~EventEngine();
    void execute();
    bool pushEvent(const Event &new_event);
    const unsigned getSizeOfQueue() const;
    const unsigned getEngineID() const;
    bool isDone() const;
    void nowDone();
};  //class EventEngine
};  //namespace DMS3

#endif // EVENTENGINE_H
