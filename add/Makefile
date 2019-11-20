all: solver generator testcases

testcases: generator
	./generator

generator: generator.cpp
	g++ -std=c++17 "$<" -o "$@" -lstdc++fs

solver: solver.cpp
	g++ -std=c++17 "$<" -o "$@" -lstdc++fs