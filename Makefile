print-%: ; @echo $*=$($*)

RM       = rm -f
CXX      = g++
CXXFLAGS = -g -std=c++0x
EXEC     = capted

all: $(EXEC)

$(EXEC): main.cpp capted.h stringnode.h
	$(CXX) $(CXXFLAGS) main.cpp -o $(EXEC)

run: all
	./capted

clean:
	$(RM) $(EXEC) *.o *.d
