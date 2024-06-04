# Mail: Roniharpaz1@gmail.com
CXX = g++
CXXFLAGS = -Wall -g -Wno-builtin-declaration-mismatch

.PHONY: all clean catan

# List of object files corresponding to existing .cpp files
OBJECTS = Board.o Catan.o demo.o Junction.o Land.o Player.o Asset.o Card.o #DevelopmentCard.o

# Default target
all: demo

# Rule to build the demo executable
demo: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

# Target to compile and run the demo
catan: demo
	./demo

# Pattern rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f *.o demo

#HOW TO RUN VALGRIND : valgrind --leak-check=full --track-origins=yes ./your_program

