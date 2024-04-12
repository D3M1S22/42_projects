# Makefile for compiling megaphone.cpp

# Compiler
CXX = c++

# Flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Executable name
TARGET = megaphone

# Source files
SRCS = megaphone.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Rule to make the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Rule to compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(TARGET)

# Clean rule
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: clean all

.phony: all clean re