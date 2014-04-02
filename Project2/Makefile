FLAGS = -Wall -Wextra -Werror -pedantic

proj2: prize.o box.o proj2.o
	g++ $(FLAGS) prize.o box.o proj2.o -o proj2

proj2.o: proj2.cpp
	g++ -c $(FLAGS) proj2.cpp -o proj2.o

box.o: box.h box.cpp
	g++ -c $(FLAGS) box.cpp -o box.o

prize.o: prize.h prize.cpp
	g++ -c $(FLAGS) prize.cpp -o prize.o
	
clean:
	rm -f *.o
	
cleanall: clean
	rm -f proj2