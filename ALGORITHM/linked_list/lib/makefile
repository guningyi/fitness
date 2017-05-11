CC := gcc
CCC := g++
CFLAGS := 
LDFLAGS := -shared
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp, %.o, $(SRCS))
TARGET_LIB := linkedList.so
RM := -rm -rf

all:$(OBJS)
	echo $(OBJS)
	$(LD) $(LDFLAGS) -o $(TARGET_LIB) $(OBJS)

%.o:%.cpp
	echo Compling $<
	$(CCC) -c $(CFLAGS) $< -o $*.o

clean:
	$(RM) $(OBJS) $(LIB) $(TARGET_LIB) *.bak *~
.PHONY:all clean
