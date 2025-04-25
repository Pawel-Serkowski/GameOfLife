COMPILER = clang++
COMPILER_FLAGS = -std=c++17
SRC = $(wildcard *.cpp)  $(wildcard Zwierzeta/*.cpp) $(wildcard Rosliny/*.cpp)
TARGET_FILE = main

all: main

main: ./*.cpp Zwierzeta/* Rosliny/*
	$(COMPILER) $(COMPILER_FLAGS) $(SRC) -o $(TARGET_FILE)

clean:
	rm -f $(TARGET)