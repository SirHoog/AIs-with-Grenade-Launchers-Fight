all: 
	g++ main.cpp src/*.cpp -o main -Iinclude -Iinclude/GameEngine -Iinclude/States -Iinclude/NC -Iinclude/NC/NumCpp -Llib/NumCpp -lsfml-graphics -lsfml-window -lsfml-system