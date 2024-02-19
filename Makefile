all: main.cpp ./Animals/ ./SFML-2.6.1/
	g++ main.cpp ./Animals/*.cpp -o zoo -I ./SFML-2.6.1/include -L ./SFML-2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system

run: 
	export LD_LIBRARY_PATH=./SFML-2.6.1/lib && ./zoo