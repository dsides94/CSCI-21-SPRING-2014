# Makefile for programming challenges
#
# CSCI 21, Spring 2014
#
# Programmer: David Sides
#

FLAGS = -Wall -Wextra -Werror -pedantic

all: pc1 pc2 pc3 pc4 pc6 pc7 pc8 pc9 pc10 pc11 pc12 pc13 pc14 pc15 pc16 proj1

proj1: proj1.cpp
	g++ $(FLAGS) proj1.cpp -o proj1

# Target for programming challenge 1
# Date completed: 1-27-2014
pc1: pc1.cpp
	g++ $(FLAGS) pc1.cpp -o pc1

# Target for programming challenge 2
# Date completed: 1-29-2014
pc2: pc2.cpp
	g++ $(FLAGS) pc2.cpp -o pc2

# Target for programming challenge 3
# Date completed: 2-3-2014
pc3: pc3.cpp
	g++ $(FLAGS) pc3.cpp -o pc3
	
# Target for programming challenge 4
# Date completed: 2-5-2014
pc4: pc4.cpp
	g++ $(FLAGS) pc4.cpp -o pc4
	
# Target for programming challenge 6
# Date completed: 2-12-2014
pc6: pc6.cpp
	g++ $(FLAGS) pc6.cpp -o pc6
	
# Target for programming challenge 7
# Date completed: 2-19-2014
pc7: pc7.cpp
	g++ $(FLAGS) pc7.cpp -o pc7
	
# Target for programming challenge 8
# Date completed: 2-24-2014
pc8: pc8.cpp
	g++ $(FLAGS) pc8.cpp -o pc8
	
# Target for programming challenge 9
# Date completed: 2-26-2014
pc9: pc9.cpp
	g++ $(FLAGS) pc9.cpp -o pc9
	
# Target for programming challenge 10
# Date completed: 3-3-2014
pc10: pc10.cpp
	g++ $(FLAGS) pc10.cpp -o pc10
	
# Target for programming challenge 11
# Date completed: 3-5-2014
pc11: pc11.cpp
	g++ $(FLAGS) pc11.cpp -o pc11
	
# Target for programming challenge 12
# Date completed: 3-10-2014
pc12: pc12.cpp
	g++ $(FLAGS) pc12.cpp -o pc12
	
# Target for programming challenge 13
# Date completed: 3-12-2014
pc13: pc13.cpp
	g++ $(FLAGS) pc13.cpp -o pc13
	
# Target for programming challenge 14
# Date completed: 3-24-2014
pc14: pc14.cpp
	g++ $(FLAGS) pc14.cpp -o pc14
	
# Target for programming challenge 15
# Date completed: 3-31-2014
pc15: pc15.cpp
	g++ $(FLAGS) pc15.cpp -o pc15
	
# Target for programming challenge 16
# Date completed: 4-2-2014
pc16: pc16.cpp
	g++ $(FLAGS) pc16.cpp -o pc16
	
