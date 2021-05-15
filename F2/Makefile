CXX=gcc
CXXFLAGS=-lm

LIBRARIES=
EXECUTABLE=output

SOURCES := ${wildcard *.c} ${wildcard **/*.c}

all: $(SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $(EXECUTABLE) $(LIBRARIES)

clean:
	rm $(EXECUTABLE)
