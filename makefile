OBJS = main.o snake.o

CXX = g++
CXXFLAGS = -Wall -std=c++17
#add libs
#LDLIBS = 

program: $(OBJS)
	$(CXX) -o program $(OBJS)

main.o = main.cpp snake.h
snake.o = snake.cpp snake.h
