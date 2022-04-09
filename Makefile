CXX = g++ 

CXXFLAGS = -Wall -std=c++11 -g

projet : projet.cpp coord.o grille.o termite.o
testcoord : testcoord.cpp coord.o 
testgrille: testgrille.cpp grille.o coord.o
testtermite : testtermite.cpp 

coord.o : coord.cpp coord.hpp 
grille.o : grille.cpp grille.hpp coord.hpp 
termite.o : termite.cpp grille.hpp coord.hpp termite.hpp

clean: 
	rm -f projet testcoord *.o
