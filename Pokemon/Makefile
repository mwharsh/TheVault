# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN = game

# Find all .cpp files and corresponding .o files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Default target
all: $(BIN)

# Link object files into final binary
$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BIN) $(OBJ_DIR)