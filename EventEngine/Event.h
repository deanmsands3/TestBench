#ifndef __DMS3_EVENT_H__
#define __DMS3_EVENT_H__
#include <cstdint>
#include <climits>
namespace DMS3{
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
		std::uint64_t _id;
		void* _payload;
	};
};
#endif
