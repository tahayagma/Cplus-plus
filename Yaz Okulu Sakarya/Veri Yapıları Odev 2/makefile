Tum: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Radix.o -c ./src/Radix.cpp
	g++ -I ./include/ -o ./lib/AvL.o -c ./src/AvL.cpp
	g++ -I ./include/ -o ./lib/node.o -c ./src/node.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Radix.o ./lib/AvL.o ./lib/node.o ./src/Test.cpp
	
calistir:
	./bin/Test