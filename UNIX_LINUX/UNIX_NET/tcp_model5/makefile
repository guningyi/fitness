CC=gcc
CFLAGS = -Wall -pg 
DEBUG = y

ifeq ($(DEBUG), y)
CFLAGS += -g
else
CFLAGS += -O2
endif

SUBDIRS := server client unp


# We use static lib here
LIBS := lib/unp.a 

LDFLAGS = -pg -g  $(LIBS)

RM = -rm -rf

__OBJS = server.o

__SRCS = $(subst .o,.c,$(__OBJS))

target = server 

MAKE = make

#all: clean $(target)
all: $(target)

$(__OBJS): $(__SRCS)
	$(CC) $(CFLAGS) -c $^ -I ./configs/


$(target): $(__OBJS)
	for dir in $(SUBDIRS); \
	do $(MAKE) -C $$dir all || exit 1; \
	done
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	@for dir in $(SUBDIRS); do make -C $$dir clean|| exit 1; done
	$(RM) $(__OBJS) $(target) *.bak *~

.PHONY: all clean
