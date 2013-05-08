# A simple Makefile for lib(libxxx.a) static lib
# the differents with the ~guningyi/Download/makefile_study/makefile_comm is
# that makefile is list of xx.c and xx.o ,but this one use the auto pattern expand
# to find the source.
CC := gcc
CFLAGS := 
AR := ar 
ARFLAGS := cr 
SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c, %.o ,$(SRCS))
TARGET_LIB := net.a
RM := -rm -rf
 
all: $(OBJS)
	echo $(OBJS)
	$(AR) $(ARFLAGS) $(TARGET_LIB) $(OBJS)

%.o:%.c
	echo Compiling $< ...
	#$(CC) -c $(CFLAGS) $< -o $*.o
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJS) $(LIB) $(TARGET_LIB) *.bak *~

.PHONY: all clean

