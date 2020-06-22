FILES = Wolf.cpp CollisionObject.cpp Game.cpp Object.cpp Draw.cpp
newer:
	g++ $(FILES) -fsanitize=address -g -o newer -lpthread  -lglut -lGLU -lGL -lm