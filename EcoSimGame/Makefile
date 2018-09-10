SOURCE_DIR = Source
INCLUDE_DIR = Source
OBJ_DIR = Source
LIB_DIR = unix/lib
BUILD_DIR = GameRoot
BUILD_FILE = EcoSimGame
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf
CXXFLAGS = -I/usr/include/SDL2 -I$(INCLUDE_DIR)

DEPS =$(wildcard $(INCLUDE_DIR)/*.h)

SRC_FILES = $(wildcard $(SOURCE_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:.cpp=.o)

$(BUILD_DIR)/$(BUILD_FILE): $(OBJ_FILES)
	$(CXX) -o $(BUILD_DIR)/$(BUILD_FILE) -L$(LIB_DIR) $^ $(LIBS)


$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp  # $(DEPS)
	$(CXX) -c -o $@ $^ $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ_DIR)/*.o $(BUILD_DIR)/$(BUILD_FILE)


# for testing variables in this Makefile
debug:
	echo $(SRC_FILES) # ok
	echo $(OBJ_FILES)  # ok
	echo $(DEPS) # ok
