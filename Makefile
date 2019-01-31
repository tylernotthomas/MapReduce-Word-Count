 lab3utilitymake: host.cpp lab3Utility.cpp
	g++ -c -std=c++0x lab3Utility.cpp
	g++ -o host.o -std=c++0x -fopenmp host.cpp lab3Utility.o
