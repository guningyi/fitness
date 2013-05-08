# A simple Makefile for lib(libxxx.a)

AR = ar
ARFLAGS = cr

LIB = unp.a

RM = -rm -rf

OBJS := unp.o  

all: $(LIB)

$(LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

clean:
	$(RM) $(OBJS) $(LIB) *.bak *~

.PHONY: all clean
