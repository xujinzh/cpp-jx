CXX = g++
INC_DIR = include
BIN_DIR = bin
TARGET = $(BIN_DIR)/xiaogu_account
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.cpp)
# OBJ = $(SRC:.cpp=.o)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

CXXFLAGS = -c -Wall -O3 -pthread $(patsubst %, -I%, $(INC_DIR))

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f ${SRC_DIR}/*.o $(TARGET)