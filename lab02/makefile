lab02.exe: main.o lab02.o
	g++ -o lab02.exe lab02.o main.o -Wall
lab02.o: lab02.cpp lab02.h
	g++ -c lab02.cpp -Wall
main.o: main.cpp lab02.h
	gcc -c main.cpp -Wall