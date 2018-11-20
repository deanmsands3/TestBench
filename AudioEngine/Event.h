#ifndef __DMS3_EVENT_H__
#define __DMS3_EVENT_H__
#include <cstdint>
#include <climits>
namespace DMS3{
	union _64bit{
		std::uint64_t _64;
		std::uint32_t _32[2];
		std::uint16_t _16[4];
		std::uint8_t _8[8];
		_64bit(std::uint64_t new_value);
	};
	struct Event{
public:
    Event();
    Event(std::uint64_t new_id, void *payload);
    Event(const Event& that);
    std::uint64_t getId() const;
    void setId(std::uint64_t id);
    void* getPayload() const;
    void setPayload(void* payload);
private:
		_64bit _id;
		void* _payload;
	};
};
#endif
