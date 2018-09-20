#include "EventEngine.h"
#include <thread>
#include <mutex>
#include <condition_variable>
namespace DMS3{

static const unsigned default_size_of_queue=1024;
static const unsigned default_engine_id=0;
EventEngine::EventEngine():
    _queue(default_size_of_queue),
    _size_of_queue(default_size_of_queue),
    _engine_id(default_engine_id),
    _done(false){
    _thread=new std::thread(EventEngine::run, this);
    }

EventEngine::EventEngine(const unsigned new_size_of_queue, const unsigned short new_engine_id):
    _queue(new_size_of_queue),
    _size_of_queue(new_size_of_queue),
    _engine_id(new_engine_id),
    _done(false){
        _thread=new std::thread(EventEngine::run, this);
    }


EventEngine::~EventEngine()
{
    if(_thread==nullptr){return;}
    if(_thread->joinable()){_thread->join();}
    delete _thread;
}

EventEngine::EventEngine(const EventEngine& that):
    _queue(that._size_of_queue),_done(that._done),_engine_id(that._engine_id),
    _size_of_queue(that._size_of_queue)
    {
    _thread=new std::thread(EventEngine::run, this);
}
bool EventEngine::pushEvent(const Event &new_event){
        //std::unique_lock<std::mutex> locker(_lockqueue);
        if(!_queue.push(new_event)){return false;}
        _queuecheck.notify_one();
        return true;
}
bool EventEngine::pushEvent(const uint64_t event_id, void *payload){
    Event e(event_id,payload);
    return pushEvent(e);
}


void EventEngine::execute()
{
  // loop until end is signaled
  while (!_done)
  {
     std::unique_lock<std::mutex> locker(_lockqueue);

     _queuecheck.wait(locker, [&]() {return !_queue.empty(); });

    this->process_events();
  }
  //std::cout<<"Exit condition received!"<<std::endl;
}

void EventEngine::run(EventEngine *ee){
    ee->execute();
}

void EventEngine::process_events(){
         // if there are values in the queue process them
     while (!_queue.empty())
     {
        DMS3::Event a;
        if(_queue.pop(a)){
            process_event(a);
        }

     }

}
void EventEngine::process_event(Event &ev){}

const unsigned EventEngine::getSizeOfQueue() const{return _size_of_queue;}
const unsigned EventEngine::getEngineID() const{return _engine_id;}
std::thread *EventEngine::getThread() const{return _thread;}
bool EventEngine::isDone() const{return _done;}
void EventEngine::nowDone(){_done=true; pushEvent(0,nullptr);}

};//namespace DMS3
