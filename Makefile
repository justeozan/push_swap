# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 10:58:27 by ozasahin          #+#    #+#              #
#    Updated: 2024/01/23 09:34:32 by ozasahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRC		=	\
			commands/push.c\
			commands/rev_rotate.c\
			commands/rotate.c\
			commands/swap.c\
			\
			src/ft_chekers.c\
			src/ft_errors.c\
			src/ft_sort_utils.c\
			src/ft_stack_utils.c\
			src/push_swap.c\
			src/sort_stack.c

OBJ		=	${SRC:.c=.o}

#Commands
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
LIBFT	=	make all -C libft/

.c.o:	include/push_swap.h include/commands.h
		@${CC} ${CFLAGS} -g3 -c $< -o ${<:.c=.o}

${NAME}:	${OBJ}
			@gcc -g3 -I include -I libft $(OBJ) -o $(NAME) -Llibft -lft

all:		${NAME}

clean:
			@${RM} ${OBJ}

fclean:		clean
			@${RM} ${NAME}

re:		fclean all
