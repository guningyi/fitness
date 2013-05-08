# A simple Makefile for lib(libxxx.so) dynamic lib
CC := gcc
LD := ld 
CFLAGS :=
LDFLAGS := -shared 
SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c, %.o ,$(SRCS))
TARGET_LIB := net.so
RM := -rm -rf
 
all: $(OBJS)
	echo $(OBJS)
	$(LD) $(LDFLAGS) -o $(TARGET_LIB) $(OBJS)

%.o:%.c
	echo Compiling $< ...
	#$(CC) -c $(CFLAGS) $< -o $*.o
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJS) $(LIB) $(TARGET_LIB) *.bak *~

.PHONY: all clean

