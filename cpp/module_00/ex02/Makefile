# Compiler
CC = c++

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRCS = Account.cpp tests.cpp

# Header files
HDRS = Account.hpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = Bank

# Build rule
all: $(EXEC)

# Target for executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Target for object files
%.o: %.cpp $(HDRS)
		$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(EXEC)

re: fclean all


.PHONY: all re clean fclean