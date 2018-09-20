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
    _done(false){}

EventEngine::EventEngine(const unsigned new_size_of_queue, const unsigned short new_engine_id):
    _queue(new_size_of_queue),
    _size_of_queue(new_size_of_queue),
    _engine_id(new_engine_id),
    _done(false){}


EventEngine::~EventEngine()
{
    //dtor
}

EventEngine::EventEngine(const EventEngine& that):
    _done(that._done),_engine_id(that._engine_id),
    _size_of_queue(that._size_of_queue),_queue(that._size_of_queue){

}
bool EventEngine::pushEvent(const Event &new_event){
        std::unique_lock<std::mutex> locker(_lockqueue);
        if(!_queue.push(new_event)){return false;}
        _queuecheck.notify_one();
        return true;
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
bool EventEngine::isDone() const{return _done;}
void EventEngine::nowDone(){_done=true;}

};//namespace DMS3
