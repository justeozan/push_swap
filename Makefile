# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 10:58:27 by ozasahin          #+#    #+#              #
#    Updated: 2024/02/12 16:54:10 by ozasahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL: all

NAME		=	push_swap

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

OBJ			=	${SRC:.c=.o}

#Commands
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

all:			force ${NAME}

${NAME}:		${OBJ}
				@$(CC) $(CFLAGS) -g3 -Iinclude -Ilibft $(OBJ) -o $(NAME) -Llibft -lft


# BONUS ------------------------------------------------
NAME_BONUS	=	checker

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

OBJ_BONUS	=	${SRC_BONUS:.c=.o}

bonus:			force $(NAME_BONUS)

${NAME_BONUS}:	${OBJ_BONUS}
				@$(CC) $(CFLAGS) -g3 -Iinclude -Ilibft $(OBJ_BONUS) -o $(NAME_BONUS) -Llibft -lft
# FIN-BONUS -------------------------------------------

.c.o:	include/push_swap.h include/commands.h
		@${CC} ${CFLAGS} -g3 -c $< -o ${<:.c=.o}

# objets/%.o:		%.c include/push_swap.h include/commands.h
# 				@${CC} ${CFLAGS} -g3 -c $< -o $@

clean:
				@${RM} ${OBJ}
				@${RM} ${OBJ_BONUS}
				@make clean -C libft

fclean:			clean
				@${RM} ${NAME}
				@${RM} $(NAME_BONUS)
				@make fclean -C libft

force:
				make -C libft

re:				fclean all

reb:			fclean bonus

.PHONY:			all bonus clean fclean force re reb
