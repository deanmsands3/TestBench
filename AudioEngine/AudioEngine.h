#pragma once
#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H
#include "EventEngine.h"
#include <SFML/Audio.hpp>
namespace DMS3{
class AudioEngine: public EventEngine
{
    public:
        AudioEngine();
        AudioEngine(const unsigned new_size_of_queue, const unsigned short new_engine_id);
        virtual ~AudioEngine();
        AudioEngine(const AudioEngine& other);

    protected:
        virtual void process_event(Event &ev);
    private:
};
}
#endif // AUDIOENGINE_H
