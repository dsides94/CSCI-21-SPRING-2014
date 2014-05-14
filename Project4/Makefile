FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

proj4: proj4.cpp Word.o BSTNode.h BSTree.h
	g++ $(FLAGS) Word.o proj4.cpp -o proj4
	
Word.o: Word.h Word.cpp
	g++ -c $(FLAGS) Word.cpp -o Word.o
	
clean:
	rm -f *.o
	
cleanall: clean
	rm -f proj4