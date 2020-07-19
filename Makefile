FILES = Wolf.cpp CollisionObject.cpp Game.cpp Object.cpp
newer:
	g++ $(FILES) -o newer -lpthread  -lglut -lGLU -lGL -lm