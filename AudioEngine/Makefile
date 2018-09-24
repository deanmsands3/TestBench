PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

OBJS = main.o AudioEngine.o EventEngine.o Event.o

CXXFLAGS=-g

all:	AudioEngineTest

AudioEngineTest:	$(OBJS)
	$(CXX) -o $@ $^ -lpthread -lsfml2-audio

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -fr AudioEngineTest $(OBJS)
