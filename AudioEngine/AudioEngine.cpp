#include "AudioEngine.h"
#include <SFML/Audio.hpp>
#include <iostream>
#include <chrono>
using namespace std::chrono_literals;
namespace DMS3{
AudioEngine::AudioEngine():EventEngine(){}
AudioEngine::AudioEngine(const unsigned new_size_of_queue, const unsigned short new_engine_id):
    EventEngine(new_size_of_queue, new_engine_id){}

void AudioEngine::process_event(DMS3::Event &ev){
    if(ev.getPayload()==nullptr){return;}
    std::cout<<"Event ID: "<<ev.getId()<<std::endl;
    sf::SoundBuffer *this_sound_buffer=((sf::SoundBuffer*)ev.getPayload());
    sf::Sound this_sound;this_sound.setBuffer(*this_sound_buffer);
    this_sound.play();
    std::this_thread::sleep_for(1000ms);
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
