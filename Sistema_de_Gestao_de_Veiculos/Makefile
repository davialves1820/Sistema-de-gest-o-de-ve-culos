CXX = g++
CXXFLAGS = -Wall -Wextra -g -Iinclude

SRC_DIR = src
OBJ_DIR = obj
BUILD_DIR = build
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/Vehicle.cpp $(SRC_DIR)/Car.cpp $(SRC_DIR)/Motorcycle.cpp $(SRC_DIR)/Truck.cpp $(SRC_DIR)/ManagerVehicle.cpp
OBJECTS = $(addprefix $(OBJ_DIR)/, $(SOURCES:$(SRC_DIR)/%.cpp=%.o))
EXECUTABLE = $(BUILD_DIR)/my_program

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)