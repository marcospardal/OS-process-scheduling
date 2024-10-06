CXX = g++

CXXFLAGS = -Wall -g -Iinclude

SRC_DIR = src
CLASS_DIR = $(SRC_DIR)/classes
BUILD_DIR = build
BIN_DIR = bin

CLASS_SOURCES = $(wildcard $(CLASS_DIR)/*.cpp)
MAIN_SOURCE = $(SRC_DIR)/main.cpp

OBJECTS = $(patsubst $(CLASS_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(CLASS_SOURCES)) \
           $(BUILD_DIR)/main.o

EXECUTABLE = $(BIN_DIR)/app.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

$(BUILD_DIR)/%.o: $(CLASS_DIR)/%.cpp
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: $(MAIN_SOURCE)
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@if exist $(BUILD_DIR) rmdir /S /Q $(BUILD_DIR)
	@if exist $(BIN_DIR) rmdir /S /Q $(BIN_DIR)
