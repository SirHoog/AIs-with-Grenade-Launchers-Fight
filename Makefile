all: 
	g++ main.cpp src/*.cpp -o main -g -Iinclude -Iinclude/GameEngine -Iinclude/States -Iinclude/NC -Iinclude/NC/NumCpp -Llib/NumCpp -lsfml-graphics -lsfml-window -lsfml-system