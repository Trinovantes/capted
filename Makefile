print-%: ; @echo $*=$($*)

RM       = rm -f
CXX      = g++
CXXFLAGS = -g -std=c++11
EXEC     = test_runner
HEADERS  = $(shell find capted -name "*.h")

all: $(EXEC)

$(EXEC): main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) main.cpp -o $(EXEC)

run: all
	./test_runner

clean:
	$(RM) $(EXEC) *.o *.d
