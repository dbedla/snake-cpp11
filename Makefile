CC=g++
LD=g++

#flags for releas target
CFLAGS=-g -std=c++0x -Wall -pedantic 

#flags for linker
LFLAGS=-lboost_thread

#flags for test target
TEST_LFLAGS=$(LFLAGS) -lcppunit

SRC := $(wildcard src/*.cpp)
TEST_SRC := $(wildcard test/test_src/*.cpp)
OBJ := $(addprefix obj/,$(notdir $(SRC:.cpp=.o)))
TEST_OBJ := $(addprefix test/test_obj/,$(notdir $(TEST_SRC:.cpp=.o)))
INC = -I include/ 


RELEASE_NAME = bin/snake
TEST_NAME = bin/t_snake


all: release
#	echo $(SRC)
#	echo $(OBJ)
#	echo $(INC)

#releas target
release: $(OBJ)
	$(LD) $(OBJ) obj/main.o -o $(RELEASE_NAME) $(LFLAGS) 


obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	$(CC) $(CFLAGS) $(INC) -c -o obj/main.o main.cpp


#test target
test: $(OBJ) $(TEST_OBJ)
	$(LD) $(OBJ) obj/main_test.o -o $(TEST_NAME) $(TEST_LFLAGS)

test/test_obj/%.o: test/test_src/%.cpp 
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	$(CC) $(CFLAGS) $(INC) -c -o obj/main_test.o main_test.cpp


#clean
clean:
	$(RM) bin/*
	$(RM) obj/*
	$(RM) test/test_obj/*

