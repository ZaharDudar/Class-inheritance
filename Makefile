all: main.cpp ./Animals/ ./SFML-2.6.1/
	g++ main.cpp ./Animals/*.cpp ./Drawer/*.cpp ./Field/*.cpp -o zoo -I ./SFML-2.6.1/include -L ./SFML-2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -g -O2

run: 
	export LD_LIBRARY_PATH=./SFML-2.6.1/lib && ./zoo

debug:
	g++ main.cpp ./Animals/*.cpp ./Drawer/*.cpp ./Field/*.cpp -o zoo -I ./SFML-2.6.1/include -L ./SFML-2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -g 
	export LD_LIBRARY_PATH=./SFML-2.6.1/lib && gdb ./zoo