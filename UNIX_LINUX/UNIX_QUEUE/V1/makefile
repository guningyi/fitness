OBJ := queue.o\
       msg.o

VPATH='/home/guningyi/Project/UNIX_QUEUE/lib'

Lumia : $(OBJ)
	g++ -o Lumia $(OBJ) Lumia.cpp
queue.o: ./lib/queue.cpp ./lib/queue.h
	g++ -c $<
msg.o: ./lib/msg.cpp ./lib/msg.h
	g++ -c $<
clean:
	rm -f *.o
	rm -rf Lumia


