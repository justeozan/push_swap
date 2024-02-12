# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 10:58:27 by ozasahin          #+#    #+#              #
#    Updated: 2024/02/12 13:34:31 by ozasahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL: all

NAME		=	push_swap

NAME_BONUS	=	checker

SRC			=	\
				commands/push.c\
				commands/rev_rotate.c\
				commands/rotate.c\
				commands/swap.c\
				\
				src/ft_errors.c\
				src/ft_sort_utils.c\
				src/ft_stack_utils.c\
				src/push_swap.c\
				src/sort_stack.c\
				src/main.c

SRC_BONUS		=	\
				commands/push.c\
				commands/rev_rotate.c\
				commands/rotate.c\
				commands/swap.c\
				\
				src/ft_errors.c\
				src/ft_sort_utils.c\
				src/ft_stack_utils.c\
				src/push_swap.c\
				src/sort_stack.c\
				src/checker.c

OBJ			=	${SRC:.c=.o}

OBJ_BONUS	=	${SRC_BONUS:.c=.o}

#Commands
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

.c.o:	include/push_swap.h include/commands.h
		@${CC} ${CFLAGS} -g3 -c $< -o ${<:.c=.o}

${NAME}:		${OBJ}
				@gcc -g3 -I include -I libft $(OBJ) -o $(NAME) -Llibft -lft

${NAME_BONUS}:	${OBJ_BONUS}
				@gcc -g3 -I include -I libft $(OBJ_BONUS) -o $(NAME_BONUS) -Llibft -lft

all:			force ${NAME}

bonus:			force $(NAME_BONUS)

clean:
				@${RM} ${OBJ}
				@${RM} ${OBJ_BONUS}
				@make clean -C libft

fclean:			clean
				@${RM} ${NAME}
				@${RM} $(NAME_BONUS)
				@make fclean -C libft

force:
				@make -C libft

re:				fclean all

reb:			fclean bonus

.PHONY:			all bonus clean fclean force re reb
