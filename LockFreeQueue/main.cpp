#include <boost/lockfree/queue.hpp>
#include <iostream>
#include <random>
#include "Event.h"
#include "EventEngine.h"
const unsigned _size_of_queue=1024;
class PrintEngine:public EventEngine{
    PrintEngine():EventEngine(){}
    PrintEngine(const unsigned new_size_of_queue, const unsigned short new_engine_id):
        EventEngine(new_size_of_queue, new_engine_id){}

    virtual void process_event(Event &ev){
        std::cout<<"Event ID: "<<ev.getId()<<", Payload: "<<(char*)ev.getPayload()<<endl;
    }
};

int main()
{
    std::random_device rd;
    auto generator = std::mt19937 {rd()};
    boost::lockfree::queue<DMS3::Event> _queue(_size_of_queue);
    std::uniform_int_distribution<uint32_t> uniform_dist;
    for(unsigned i=0;i<_size_of_queue;i++){
        DMS3::Event a(uniform_dist(generator),nullptr);
        bool truth=_queue.push(a);
        std::cout<<"Pushed: "<<a.getId()<<" which returned: "<<truth<<std::endl;
    }
    for(unsigned i=0;i<_size_of_queue;i++){
        DMS3::Event a;
        bool truth=_queue.pop(a);
        std::cout<<"Popped: "<<a.getId()<<" which returned: "<<truth<<std::endl;
    }

    return 0;
}
