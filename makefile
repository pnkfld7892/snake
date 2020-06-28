OBJS = main.o snake.o bodyCell.o food.o

CXX = g++
CXXFLAGS = -Wall -std=c++17 
#add libs
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -L /usr/lib64

snakeGame.app: $(OBJS)
	$(CXX) -o snakeGame.app $(OBJS) $(LDLIBS)

main.o = main.cpp snake.h direction.h
snake.o = snake.cpp snake.h bodyCell.h
bodyCell.o = bodyCell.cpp
food.o = food.cpp 
clean:
	$(RM) snakeGame.app $(OBJS)
