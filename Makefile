print-%: ; @echo $*=$($*)

RM       = rm -f
CXX      = clang++
CXXFLAGS = -g -Wall -std=c++11 -stdlib=libc++ -MMD -I./lib -I.
LDFLAGS  = -stdlib=libc++
HEADERS  = $(shell find lib -name "*.h")

SRC_DIR = tests
BIN_DIR = bin
SRCS = $(shell find tests -type f -name *.cpp)
OBJS = $(subst $(SRC_DIR),$(BIN_DIR),$(subst .cpp,.o,$(SRCS)))
EXEC = $(BIN_DIR)/test_runner

all: $(EXEC) $(BIN_DIR)

$(BIN_DIR):
	mkdir -p $@

$(EXEC): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

-include $(OBJ_DIR)/*.d

run: all
	./bin/test_runner

clean:
	$(RM) $(EXEC) $(BIN_DIR)/*.o $(BIN_DIR)/*.d
