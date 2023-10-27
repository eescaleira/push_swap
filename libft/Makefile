# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 16:03:03 by eescalei          #+#    #+#              #
#    Updated: 2023/10/27 22:00:35 by eescalei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ./printf/

SRC = 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strncmp.c ft_toupper.c ft_tolower.c ft_strrchr.c ft_strnstr.c ft_strdup.c\
		ft_atoi.c ft_memcmp.c ft_memmove.c ft_memset.c ft_memcpy.c ft_memchr.c ft_bzero.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_calloc.c\
		ft_substr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_strjoin.c ft_strtrim.c ft_striteri.c ft_itoa.c ft_split.c
SRCB =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

FT_PRINTF_PATH = ./ft_printf/
FT_PRINTF_NAME = libftprintf.a

OBJS = ${SRC:.c=.o}
OBJSB = ${SRCB:.c=.o}

FT_PRINTF = $(FT_PRINTF_PATH)$(FT_PRINTF_NAME)

RM = rm -f

all:	${NAME} $(FT_PRINTF)

$(NAME):	${OBJS}	$(HEADER)
		ar rcs ${NAME} ${OBJS} $(FT_PRINTF) ${HEADER}

$(FT_PRINTF):
	make -sC $(FT_PRINTF_PATH)

.c.o:
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

	
clean:
	${RM} ${OBJS}
	${RM} ${OBJSB}
	make clean -sC $(FT_PRINTF_PATH)

fclean:	clean
		${RM} ${NAME}
		make fclean -sC $(FT_PRINTF_PATH)

re:	fclean all

bonus:	${OBJS} ${OBJSB} $(FT_PRINTF)
		ar rcs ${NAME} ${OBJSB} ${OBJS} $(FT_PRINTF) ${HEADER}

.PHONY: all clean fclean re bonus