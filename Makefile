CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I./src

TARGET = biblioteca

SRC = $(wildcard src/*.cpp) \
      $(wildcard src/dominio/*.cpp) \
      $(wildcard src/datatypes/*.cpp) \
      $(wildcard src/controladores/*.cpp) \
      $(wildcard src/presentacion/*.cpp) \
      $(wildcard src/utils/*.cpp)

OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
./$(TARGET)

clean:
rm -f $(OBJ) $(TARGET)

.PHONY: all run clean
