FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

proj4: proj4.o Word.o
	g++ $(FLAGS) Word.o proj4.o -o proj4

proj4.o: proj4.cpp BSTNode.h BSTree.h
	g++ -c $(FLAGS) proj4.cpp -o proj4.o

Word.o: Word.h Word.cpp
	g++ -c $(FLAGS) Word.cpp -o Word.o
	
clean:
	rm -f *.o
	
cleanall: clean
	rm -f proj4