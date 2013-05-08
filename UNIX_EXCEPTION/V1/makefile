OBJ := exception.o
       

VPATH='/home/guningyi/Project/UNIX_EXCEPTION/lib'

Lumia : $(OBJ)
	g++ -o Lumia $(OBJ) Lumia.cpp

exception.o: ./lib/exception.cpp ./lib/exception.h	
	g++ -c $<
clean:
	rm -f *.o
	rm -rf Lumia

