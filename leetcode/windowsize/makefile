src = $(wildcard *.cpp)
targets = $(patsubst %.cpp, %, $(src))
INCLUDE = -I ./
CC = g++
CFLAGS =  -g -std=c++11
#-Wall
LIBS  = -lm -lstdc++ 
all:$(targets)

$(targets):%:%.cpp
	$(CC) $(INCLUDE) $(CFLAGS) $< -o $@ $(LIBS)

.PHONY:clean all
clean:
	-rm -rf $(targets) 
#438找到字符串中所有字母异位词