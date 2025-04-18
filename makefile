COMPILER = clang++
COMPILER_FLAGS = -std=c++17
SRC = $(wildcard *.cpp)  $(wildcard Zwierzeta/*.cpp) $(wildcard Rosliny/*.cpp) $(wildcard Czlowiek/*.cpp) 
TARGET_FILE = main

all: main

main: ./*.cpp Zwierzeta/* Rosliny/* Czlowiek/*
	$(COMPILER) $(COMPILER_FLAGS) $(SRC) -o $(TARGET_FILE)

clean:
	rm -f $(TARGET)