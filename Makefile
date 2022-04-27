all : main
CXX = g++
CXXFLAGS = -std=c++11 -Wall 
EXEC_FILES = main

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $<

main : ensemble.o main.o coord.o
	$(CXX) -o $@ $^

ensemble.o : ensemble.hpp 

coord.o : coord.hpp ensemble.hpp

main.o : coord.hpp ensemble.hpp

clean:
	rm -f *.o $(EXEC_FILES)