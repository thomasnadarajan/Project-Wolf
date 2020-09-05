FILES = Wolf.cpp CollisionObject.cpp Game.cpp Object.cpp
FLAGS = -o newer -lpthread  -lglut -lGLU -lGL -lm
detected_OS := $(shell uname -s)
ifeq ($(detected_OS),Darwin)        # macOS
	FLAGS = -std=c++11 -o newer -framework GLUT -framework OpenGL
endif
newer:
		g++ -fsanitize=address -g $(FILES) $(FLAGS)