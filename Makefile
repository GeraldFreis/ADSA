runall: main.cpp
	g++ -o main.out -std=c++11 -O2 -Wall main.cpp
	echo "000,000,000 ABD,BAC,DCA ABD,BAC,DCA" | ./main.out