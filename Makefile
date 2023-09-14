all: 
	g++ -o main main.cpp -Iinclude -Iinclude/GameEngine -Iinclude/NC -Iinclude/NC/NumCpp -Llib/NumCpp -lsfml-graphics -lsfml-window -lsfml-system