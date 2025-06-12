# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -std=c++17
# Target executable
TARGET = queue
# Source file
SRC = Queue.cpp

# Default target
all: $(TARGET)

# How to build the target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean up
clean:
	rm -f $(TARGET)