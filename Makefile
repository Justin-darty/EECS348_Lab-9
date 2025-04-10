# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Executable Output
TARGET = matrix_operations

# Source Files
SRCS = main.cpp matrix.cpp

# Object Files
OBJS = $(SRCS:.cpp=.o)

# Build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Clean up object and executable files
clean:
	rm -f $(OBJS) $(TARGET)
