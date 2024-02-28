run:
	./main

built:
	g++ -o main main.cpp kNN.cpp -I . -std=c++11

