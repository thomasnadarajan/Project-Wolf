FILES = Wolf.cpp CollisionObject.cpp Game.cpp Object.cpp
FLAGS = -o newer -lpthread  -lglut -lGLU -lGL -lm
detected_OS := $(shell uname -s)
ifeq ($(detected_OS),Darwin)        # Mac OS X
	FLAGS = -std=c++11 -o newer -framework GLUT -framework OpenGL
endif
newer:
		g++ $(FILES) $(FLAGS)