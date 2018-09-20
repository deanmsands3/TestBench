PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

OBJS = main.o EventEngine.o Event.o

CXXFLAGS=-g

all:	EventEngineTest

EventEngineTest:	$(OBJS)
	$(CXX) -o $@ $^ -lpthread

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -fr EventEngineTest $(OBJS)
