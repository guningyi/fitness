
CCC := g++
CFLAGS :=
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp, %.o, $(SRCS))
TARGET := Lumia
LD := ld
RM := -rm -rf


all:$(OBJS)
	echo $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)

%.o:%.cpp
	echo Compling...$<
	$(CCC) -c $(CFLAGS) $< -o $@
clean:
	$(RM) $(TARGET) $(OBJS) *.bak *.~
.PHONY:all clean
