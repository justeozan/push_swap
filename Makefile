# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 10:58:27 by ozasahin          #+#    #+#              #
#    Updated: 2024/02/13 14:54:32 by ozasahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL: all

NAME	= push_swap

SRC		=		\
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

OBJDIR	= obj
OBJ		= $(patsubst %,$(OBJDIR)/%,$(SRC:.c=.o))

# Controls
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all:	force $(NAME)

$(NAME):	$(OBJ)
				@$(CC) $(CFLAGS) -g3 -Iinclude -Ilibft $(OBJ) -o $(NAME) -Llibft -lft

# BONUS ------------------------------------------------
NAME_BONUS	= checker

SRC_BONUS   = \
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

OBJ_BONUS	= $(patsubst %,$(OBJDIR)/%,$(SRC_BONUS:.c=.o))

bonus:	force $(NAME_BONUS)

$(NAME_BONUS):	$(OBJ_BONUS)
				@$(CC) $(CFLAGS) -g3 -Iinclude -Ilibft $(OBJ_BONUS) -o $(NAME_BONUS) -Llibft -lft
# END-BONUS -------------------------------------------

$(OBJDIR)/%.o:	%.c include/push_swap.h include/commands.h | $(OBJDIR)
				@$(CC) $(CFLAGS) -g3 -Iinclude -Ilibft -c $< -o $@

$(OBJDIR):
				mkdir -p $(OBJDIR)
				mkdir -p $(OBJDIR)/commands
				mkdir -p $(OBJDIR)/src

clean:
				@$(RM) -r $(OBJDIR)

fclean:	clean
				@$(RM) $(NAME)
				@$(RM) $(NAME_BONUS)
				@make fclean -C libft

force:
				@make -C libft

re:		fclean all

reb:	clean bonus

.PHONY:	all bonus clean fclean force re reb
