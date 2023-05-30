makeall: main.cpp
	g++ -o main.out -std=c++11 -O2 -Wall main.cpp
	./a.out
makenew: newmain.cpp
	g++ -o newmain.out -std=c++11 -O2 -Wall newmain.cpp