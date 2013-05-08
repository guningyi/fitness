# makefile
CC := g++
LD := ld
CFLAGS :=
LDFLAGS := -shared
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp, %.o ,$(SRCS))
#TARGET_LIB := net.so
TARGET := StatePattern
RM := -rm -rf

all: $(OBJS)
	echo $(OBJS)
	$(LD) $(LDFLAGS) -o $(TARGET) $(OBJS)

%.o:%.cpp
	echo Compiling $< ...
	#$(CC) -c $(CFLAGS) $< -o $*.o
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJS) $(LIB) $(TARGET_LIB) *.bak *~

.PHONY: all clean

