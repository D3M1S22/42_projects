#SETUP
NAME		=	pipex
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g
# FLAGS_D		=	-Wall -Wextra -Werror -g -D DEBUGGER=1
RM			=	rm -rf

#FILES AND PATH
HEADER_SRCS	=	pipex.h pipex_bonus.h
HEADER_DIR	=	include/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS	=	pipex.c child.c error.c free.c debug.c
MPATH_DIR	=	src/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)


FUNC_SRCS	=	ft_strncmp.c ft_strdup.c ft_split.c ft_strjoin.c ft_putnbr.c ft_putstr.c ft_print_pipe.c ft_int_to_str.c
FUNC_DIR	=	string_utils/
FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))\
					main.c
OBJ_F		=	$(FUNC:.c=.o)
LOG_F		= debug/log_*

#COMMANDS
%.o: %.c $(HEADER) Makefile
				@${CC} ${FLAGS} -c $< -o $@

$(NAME):		$(OBJ_F) $(OBJ_M)
				@$(CC) $(OBJ_F) $(OBJ_M) -fsanitize=address -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

clean:
				@$(RM) $(OBJ_M)
				@$(RM) $(OBJ_F)
				@$(RM) $(OBJ_B)
				@$(RM) $(LOG_F)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m