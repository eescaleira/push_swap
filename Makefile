# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 13:37:37 by eescalei          #+#    #+#              #
#    Updated: 2023/10/29 12:18:48 by eescalei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I ./inc/ -I ./libft/

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/

LIB_PATH = ./libft/
LIB_NAME = libft.a
LIB = $(LIB_PATH)$(LIB_NAME)

RM = rm -rf

SOURCES =	main.c \
			sort_stack.c \
			general_moves.c \
			movements.c \
			stack_operations.c \
			utils.c \
			variables_calcs.c \
			print_stack.c 

SRCS = $(addprefix $(SRC_PATH),$(SOURCES))
OBJ = $(SOURCES:.c=.o)
OBJS = $(addprefix $(OBJ_PATH),$(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

clean: 
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re