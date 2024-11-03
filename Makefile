# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall

# Target executable
TARGET = main_exe

# Default target to build the executable
$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp

# Clean up compiled files
clean:
	rm -f $(TARGET)