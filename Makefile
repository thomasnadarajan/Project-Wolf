FILES = game.cpp CollisionObject.cpp
newer:
	g++ $(FILES) -o newer -lpthread  -lglut -lGLU -lGL -lm