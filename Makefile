# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 10:58:27 by ozasahin          #+#    #+#              #
#    Updated: 2024/01/12 11:25:44 by ozasahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap.a

SRC		=	src/push_swap.c

OBJ		=	${SRC:.c=.o}

#Commands
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
LIBFT	=	make all -C libft/

.c.o:	push_swap.h
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ}
			ar rc ${NAME} ${OBJ}

all:		${NAME}

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:		fclean all
