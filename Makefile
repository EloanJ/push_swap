# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 19:53:51 by ejonsery          #+#    #+#              #
#    Updated: 2024/12/17 13:00:20 by ejonsery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

SRC = combo.c \
		push_swap.c\
		swap_a.c\
		swap_b.c\
		utils.c\
		quiet.c\
		best_moove.c\
		back_to_a.c \
		quick_sort.c

OBJ = ${SRC:.c=.o}

INCLUDES = -I .

FLAGS = -Wall -Werror -Wextra -g3

MAKELIB = ${MAKE} -C ./libft

LIBFT = ./libft/libft.a

all : ${NAME}

${NAME} : ${OBJ}
	${MAKELIB}
	${CC} -o ${NAME} ${SRC} ${LIBFT} ${INCLUDES} ${FLAGS}

%.o : %.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

clean :
		rm -f ${OBJ}
		${MAKE} -C ./libft clean

fclean : clean
		rm -f ${NAME}
		${MAKE} -C ./libft fclean

re : fclean all

.PHONY: all clean fclean re