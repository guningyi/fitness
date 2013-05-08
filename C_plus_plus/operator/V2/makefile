#OBJS:= operator.o

CCC := g++
CFLAGS :=
LDFLAGS := -shared
LD := ld

OBJS := operator.o

TARGET := Lumia
RM := -rm -rf


$(TARGET):$(OBJS)
	echo $(OBJS)
	$(CCC)  -o $(TARGET) $(OBJS) ./Lumia.cpp

operator.o: ./operator.cpp ./operator.h
	echo Compling $<
	$(CCC) -c $<

clean:
	$(RM) $(TARGET) $(OBJS) *.bak *.~

.PHONY:all clean 
	



