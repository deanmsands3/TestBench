#include "AudioEngine.h"
#include <SFML/Audio.hpp>
namespace DMS3{
AudioEngine::AudioEngine():EventEngine(){}
AudioEngine::AudioEngine(const unsigned new_size_of_queue, const unsigned short new_engine_id):
    EventEngine(new_size_of_queue, new_engine_id){}

void AudioEngine::process_event(Event &ev){
    if(ev.getPayload()==nullptr){return;}
    std::cout<<"Event ID: "<<ev.getId()<<", Payload: "<<(char*)ev.getPayload()<<std::endl;
}

AudioEngine::~AudioEngine()
{
    //dtor
}

AudioEngine::AudioEngine(const AudioEngine& other)
{
    //copy ctor
}

};
