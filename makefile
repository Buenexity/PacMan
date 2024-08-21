all: compile link test

compile:
	g++ -Isrc/include -c sacman_src/main.cpp -o build/main.o
	g++ -Isrc/include -c sacman_src/object.cpp -o build/object.o
	g++ -Isrc/include -c sacman_src/ghost.cpp -o build/ghost.o
	g++ -Isrc/include -c sacman_src/pacman.cpp -o build/pacman.o
	g++ -Isrc/include -c sacman_src/backgroundSounds.cpp -o build/backgroundSounds.o
	g++ -Isrc/include -c sacman_src/Map.cpp -o build/Map.o
	g++ -Isrc/include -c sacman_src/collisions.cpp -o build/collisions.o
	g++ -Isrc/include -c sacman_src/MainMenu.cpp -o build/MainMenu.o

link:
	g++ build/main.o build/Map.o build/object.o build/collisions.o build/pacman.o build/MainMenu.o build/ghost.o build/backgroundSounds.o -o build/main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lsfml-audio

test: compile
	g++ -Isrc/include -c tests/pacman_test.cpp -o build/pacman_test.o 
	g++ -Isrc/include -c tests/ghost_test.cpp -o build/ghost_test.o
	g++ -Isrc/include -c tests/collisions_test.cpp -o build/collisions_test.o
	g++ -Isrc/include -c tests/object_test.cpp -o build/object_test.o
	g++ -Isrc/include -c tests/map_test.cpp -o build/map_test.o
	g++ build/pacman_test.o build/ghost_test.o build/collisions_test.o build/object_test.o build/map_test.o build/Map.o build/object.o build/collisions.o build/pacman.o build/MainMenu.o build/ghost.o build/backgroundSounds.o -o build/test -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lsfml-audio

.PHONY: all compile link test
