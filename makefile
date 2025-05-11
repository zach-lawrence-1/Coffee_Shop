CXX = g++
CXXFLAGS = -std=c++17 -pedantic -Wall -Wextra -g

coffee: coffee.h coffee.cpp main.cpp
	$(CXX) $(CXXFLAGS) -o coffee coffee.h coffee.cpp main.cpp
