OBJ := linkedList.o\
       singleNode.o

VPATH='../lib'

Lumia : $(OBJ)
	g++ -o reverse_single_linked_list $(OBJ) reverse_single_linked_list.cpp
linkedList.o: ../lib/linkedList.cpp ../lib/linkedList.h
	g++ -c $<
singleNode.o: ../lib/singleNode.cpp ../lib/singleNode.h
	g++ -c $<
clean:
	rm -f *.o
	rm -rf reverse_single_linked_list
