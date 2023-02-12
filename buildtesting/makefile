OUTPUT=prog

OUT_DIR=bin
BUILD_DIR=build
SRC_DIR=src

CC=gcc
CXX=g++
RM=rm -f

CPPFLAGS= -pthread -MP -MMD
LDFLAGS= 
LDLIBS= -lglfw3 -lopengl32 -lpthread

SRCS=$(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

all: $(OUTPUT)

makefiledebug:
	echo $(SRCS)
	echo $(OBJS)
	echo $(DEPS)

$(OUTPUT): $(OBJS)
	mkdir -p $(dir $@)
	echo $(DEPS)
	$(CXX) $(LDFLAGS) -o $(OUT_DIR)/$(OUTPUT) $(OBJS) $(LDLIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BUILD_DIR)/*
	$(RM) $(OUT_DIR)/*

-include $(DEPS)