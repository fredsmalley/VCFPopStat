#	Fred Smalley
#	PopStat makefile
#	created:	4-9-2015
#

# Set Environment
export PROJECT_ROOT := $(CURDIR)

# Variables
TARGET = PopStat
OBJS := $(patsubst src/%.cpp, obj/%.o, $(wildcard src/*.cpp))
CXX = g++
CXXFLAGS = -std=c++11 -I $(PROJECT_ROOT)/include

# Default rule
all:	env $(TARGET)

env:
	echo $(PROJECT_ROOT)

$(TARGET) :	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(CXXFLAGS)

# Rules
obj/%.o :	src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm $(TARGET) $(OBJS)
