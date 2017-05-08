# A simple Makefile for lib(libxxx.a)

AR = ar
ARFLAGS = cr

LIB = server.a

RM = -rm -rf

OBJS := server.o 

all: $(LIB)

$(LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

clean:
	$(RM) $(OBJS) $(LIB) *.bak *~

.PHONY: all clean
