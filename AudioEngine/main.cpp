#include "EventEngine.h"
#include "AudioEngine.h"
#include "ByteArray.h"
#include <boost/lockfree/queue.hpp>
#include <iostream>
#include <random>
#include <chrono>
using namespace std::chrono_literals;
const unsigned _size_of_queue=1024;
int main()
{
    DMS3::AudioEngine ae(32,1);
    std::thread *ae_thread=ae.getThread();
    std::vector<ByteArray>bav;
	std::vector<sf::SoundBuffer> buffers;
    std::vector<sf::Sound> sounds;
    std::vector<std::string> wavs={"blaster.ogg","fwip.ogg","jump.ogg","swim.ogg"};
    for(std::string wav:wavs){
        ByteArray ba(wav);
    	bav.push_back(ba);
    }
    for(ByteArray ba:bav){
    	sf::SoundBuffer soundbuffer;
    	soundbuffer.loadFromMemory(ba.data(),ba.length());
    	buffers.push_back(soundbuffer);
    }
//    for(sf::SoundBuffer buffer:buffers){
//    	sf::Sound sound;
//    	sound.setBuffer(buffer);
//    	sounds.push_back(sound);
//    	sound.play();std::this_thread::sleep_for(1000ms);
//    }
    for(unsigned i=0;i<ae.getSizeOfQueue();i++){
    	int j=i%bav.size();
    	void *payload=(void*)(&buffers[j]);
		DMS3::Event a(i,payload);
		ae.pushEvent(a);
    }
	ae.nowDone();
    ae_thread->join();
    sounds.clear();
    buffers.clear();
    bav.clear();
    return 0;
}
