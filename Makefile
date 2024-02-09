
SRC = src/*.cpp imgui/*.cpp
IDIR = -Iinclude -Iimgui
LIBDIR = -Llib
LIBS = -lsfml-graphics-d-2 -lsfml-system-d-2 -lsfml-window-d-2 -lopengl32

all:
	g++ -o bin/fractal $(SRC) $(IDIR) $(LIBDIR) $(LIBS)
