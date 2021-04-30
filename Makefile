main : main.cpp document.cpp csvdb.cpp common.cpp db.h
	g++ -std=c++17 -o main main.cpp document.cpp csvdb.cpp common.cpp -I.
#main : main.o document.o ioutils.o common.o
#	g++ -std=c++17 -Wall -o main document.o ioutils.o common.o

#main.o : main.cpp common.h document.h ioutils.h
#	g++ -std=c++17 -Wall main.cpp

#document.o : document.cpp ioutils.h 
#	g++ -c -std=c++17 -Wall document.cpp

#ioutils.o : ioutils.cpp common.h
#	g++ -c -std=c++17 -Wall ioutils.cpp

#common.o : common.cpp
#	g++ -c -std=c++17 -Wall common.cpp
