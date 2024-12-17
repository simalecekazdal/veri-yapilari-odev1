all: derle bagla calistir

derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/DNA.cpp -o ./lib/DNA.o
	g++ -c -I "./include" ./src/Gen.cpp -o ./lib/Gen.o
	g++ -c -I "./include" ./src/Kromozom.cpp -o ./lib/Kromozom.o

bagla:
	g++ ./lib/DNA.o ./lib/Gen.o ./lib/main.o ./lib/Kromozom.o -o ./bin/program

calistir:
	./bin/program