/*
 * Event.cpp
 *
 *  Created on: Jun 9, 2018
 *      Author: deanm
 */
#include "Event.h"


namespace DMS3{
    Event::Event():
        _id(0), _payload(nullptr){}

    Event::Event(std::uint64_t new_id, void *new_payload):
        _id(new_id), _payload(new_payload){}

    Event::Event(const Event& that) {
        this->_id=that._id;
        this->_payload=that._payload;
    }

    std::uint64_t Event::getId() const {
        return _id;
    }

    void Event::setId(std::uint64_t id) {
        _id = id;
    }

    void* Event::getPayload() const {
        return _payload;
    }


    void Event::setPayload(void* payload) {
        _payload = payload;
    }

};

