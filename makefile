OBJS = main.o snake.o

CXX = g++
CXXFLAGS = -Wall -std=c++17
#add libs
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system 

program.app: $(OBJS)
	$(CXX) -o program.app $(OBJS) $(LDLIBS)

main.o = main.cpp snake.h
snake.o = snake.cpp snake.h
clean:
	$(RM) program.app $(OBJS)
