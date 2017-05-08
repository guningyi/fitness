OBJ := hash.o

Lumia : $(OBJ)
	g++ -o Lumia $(OBJ) Lumia.cpp

hash.o: ./hash.cpp ./hash.h
	g++ -c $<

clean:
	rm -f *.o
	rm -rf Lumia


