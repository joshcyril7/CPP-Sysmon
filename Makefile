CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -lncurses

SRCS = main.cpp cpu.cpp memory.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = sysmon

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

clean:
	rm -f *.o $(EXEC)
