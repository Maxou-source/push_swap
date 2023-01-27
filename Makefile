# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 00:26:59 by mparisse          #+#    #+#              #
#    Updated: 2023/01/26 01:11:00 by mparisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = psh_swp.c parsing.c movements.c utils.c tmp_utils.c algo_utils.c algo_utils2.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap

CC = gcc -g3

CFLAGS = -Wall -Werror -Wall

LIBS = libft.a -lm

all : ${NAME}

${NAME}: ${OBJS}
	@make --no-print-directory -C libft
	@cp libft/libft.a .
	${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME} 

.c.o :
	${CC} -Wall -Werror -Wall -c $< -o ${<:.c=.o}

norme : 
	norminette ${SRCS}

clean :
	make --no-print-directory -C libft/ clean
	rm -rf ${OBJS}
	
fclean : clean
	rm -rf ${NAME}
	rm -rf libft.a
	
re : fclean ${NAME}

.PHONY: all clean fclean re norme libft
.SILENT:
