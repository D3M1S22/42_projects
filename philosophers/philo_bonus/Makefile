NAME = philo_bonus
CC = gcc

FLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)

PHILO_OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PHILO_OBJS)
	@$(CC) $(FLAGAS) $(PHILO_OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo " - Removing object files..."
	@rm -rf $(PHILO_OBJS)

fclean:
	@echo " - Removing files..."
	@rm -rf $(NAME)

re: clean all