#include "EventEngine.h"
#include <boost/lockfree/queue.hpp>
#include <iostream>
#include <random>
const unsigned _size_of_queue=1024;
namespace DMS3{
class PrintEngine : public EventEngine {
    public:
    PrintEngine():EventEngine(){}
    PrintEngine(const unsigned new_size_of_queue, const unsigned short new_engine_id):
        EventEngine(new_size_of_queue, new_engine_id){}

    virtual void process_event(Event &ev){
        if(ev.getPayload()==nullptr){return;}
        std::cout<<"Event ID: "<<ev.getId()<<", Payload: "<<(char*)ev.getPayload()<<std::endl;
    }
};
};

const char *SillyMessages[]={
    "Never pet a burning dog.",
    "This isn't even my final form.",
    "How much wood could a woodchuck chuck?",
    "No. This is Patrick!",
    "A winner is you!"
};

int main()
{
    std::random_device rd;
    auto generator = std::mt19937 {rd()};
    std::uniform_int_distribution<uint32_t> uniform_dist;
    //boost::lockfree::queue<DMS3::Event> _queue(_size_of_queue);
    DMS3::PrintEngine pe(1024,1);
    std::thread *pe_thread=pe.getThread();

    for(unsigned i=0;i<pe.getSizeOfQueue();i++){
        DMS3::Event a(uniform_dist(generator),(void*)SillyMessages[i%5]);
        bool truth=pe.pushEvent(a);
        //std::cout<<"Pushed: "<<a.getId()<<" which returned: "<<truth<<std::endl;
    }
    pe.nowDone();
    pe_thread->join();
    return 0;
}
