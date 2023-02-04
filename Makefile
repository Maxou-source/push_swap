# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 00:26:59 by mparisse          #+#    #+#              #
#    Updated: 2023/02/03 21:38:16 by mparisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c parsing.c movements.c utils.c tmp_utils.c algo_utils_median.c apply_price.c \
price_calculation.c freee.c movements_2.c utils_2.c 

BONUS_SRCS = bonus/get_next_line/get_next_line.c \
bonus/get_next_line/get_next_line_utils.c bonus/main_bonus.c \
bonus/movements_checker.c movements_2.c movements.c algo_utils_median.c utils_2.c \
utils.c freee.c parsing.c tmp_utils.c 

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${BONUS_SRCS:.c=.o}

NAME = push_swap

CC = gcc -g3

CFLAGS = -Wall -Werror -Wall

LIBS = libft.a

LIBS_BONUS = ../libft.a

all : ${NAME}

${NAME}: ${OBJS}
	@make --no-print-directory -C libft
	@cp libft/libft.a .
	${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME} 

.c.o :
	${CC} -Wall -Werror -Wall -c $< -o ${<:.c=.o}

bonus : ${OBJS_BONUS}
	${CC} ${CFLAGS} ${OBJS_BONUS} ${LIBS} -o checker

norme : 
	norminette ${SRCS}

clean :
	make --no-print-directory -C libft/ clean
	rm -rf ${OBJS_BONUS}
	rm -rf ${OBJS}
	
fclean : clean
	rm -rf ${NAME}
	rm -rf checker
	rm -rf libft.a
	
re : fclean ${NAME}

.PHONY: all clean fclean re norme libft bonus
# .SILENT:
