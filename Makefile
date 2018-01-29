print-%: ; @echo $*=$($*)

RM       = rm -f
CXX      = g++
CXXFLAGS = -g -std=c++0x
EXEC     = test_runner

all: $(EXEC)

$(EXEC): main.cpp capted/*.h
	$(CXX) $(CXXFLAGS) main.cpp -o $(EXEC)

run: all
	./test_runner

clean:
	$(RM) $(EXEC) *.o *.d
