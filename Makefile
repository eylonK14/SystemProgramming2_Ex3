CXX=clang++
CXXFLAGS=-std=c++2a -Werror -Wsign-conversion -g


# Assuming Demo.cpp and Test.cpp are your main .cpp files
SOURCES=Test.cpp Board.cpp board/Hexagon.cpp board/Vertex.cpp board/Edge.cpp board/Terrain.cpp
DEMO_SOURCES=Demo.cpp Board.cpp board/Hexagon.cpp board/Vertex.cpp board/Edge.cpp board/Terrain.cpp Player.cpp
OBJECTS=$(SOURCES:.cpp=.o)
DEMO_OBJECTS=$(DEMO_SOURCES:.cpp=.o)

catan: demo
	./$^

all: demo test

demo: $(DEMO_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

test: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

tidy:
	clang-tidy $(SOURCES) $(DEMO_SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

# Implicit rule for compiling source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@  # Use implicit rule

.PHONY: clean all

clean:
	rm -f board/*.o *.o demo test