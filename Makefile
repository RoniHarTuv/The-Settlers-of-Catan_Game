# Mail: Roniharpaz1@gmail.com
CXX = g++
CXXFLAGS = -Wall -g -Wno-builtin-declaration-mismatch

.PHONY: all clean catan test 

OBJECTS = Board.o Catan.o demo.o Junction.o Land.o Player.o Asset.o Card.o DevelopmentCard.o PlayerForTest.o
ST=Board.cpp Catan.cpp Junction.cpp Land.cpp Player.cpp Asset.cpp Card.cpp DevelopmentCard.cpp PlayerForTest.cpp
OBJECTSTEST=$(subst .cpp,.o,$(SOURCESTEST))
SOURCESTEST=TestCounter.cpp Test.cpp 
OT= $(subst .cpp,.o,$(ST))

all: demo

demo: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestCounter.o Test.o $(OT)
	$(CXX) $(CXXFLAGS) $^ -o test

catan: demo
	./demo

tidy:
	clang-tidy Board.cpp Catan.cpp demo.cpp Junction.cpp Land.cpp Player.cpp Asset.cpp Card.cpp DevelopmentCard.cpp -checks=bugprone-*,g++-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f *.o demo

#HOW TO RUN VALGRIND : valgrind --leak-check=full --track-origins=yes ./your_program
#HOW TO RUN CLANG:  clang-format -i Asset.cpp

