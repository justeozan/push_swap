# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 10:58:27 by ozasahin          #+#    #+#              #
#    Updated: 2024/01/15 14:55:54 by ozasahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRC		=	\
			src/ft_chekers.c\
			src/ft_errors.c\
			src/ft_stack_utils.c\
			src/push_swap.c

OBJ		=	${SRC:.c=.o}

#Commands
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
LIBFT	=	make all -C libft/

.c.o:	include/push_swap.h
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ}
			gcc -I include -I libft $(OBJ) -o $(NAME) -Llibft -lft

all:		${NAME}

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:		fclean all
