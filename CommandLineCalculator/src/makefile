CXX = g++
CXXFLAGS = -Wall -g



main: main.o Point.o Rectangle.o
	$(CXX) $(CXXFLAGS) -o main main.o Point.o Rectangle.o

# The main.o target can be written more simply

main.o: Main.h CalculatorApp.o

$(CXX) $(CXXFLAGS) -c main.cpp

Point.o: Point.h

Rectangle.o: Rectangle.h Point.h