# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 10:58:27 by ozasahin          #+#    #+#              #
#    Updated: 2024/02/16 16:45:37 by ozasahin         ###   ########.fr        #
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
CFLAGS_TEST	= -Wall -Wextra -Werror -fsanitize=address
RM		= rm -f

# Colors
COLOR_RESET		=\033[0m
COLOR_RED		=\033[0;31m
COLOR_GREEN		=\033[0;32m
COLOR_PURPLE	=\033[0;95m
COLOR_BLUE		=\033[0;34m

# Messages colorés
MESSAGE_COMPILE		=$(COLOR_BLUE)Compiling the program...$(COLOR_RESET)
MESSAGE_DONE		=$(COLOR_GREEN)Compilation completed.$(COLOR_RESET)
MESSAGE_CLEAN		=$(COLOR_PURPLE)Cleaning up...$(COLOR_RESET)
MESSAGE_CLEAN_DONE	=$(COLOR_PURPLE)Cleanup completed.$(COLOR_RESET)

all:	force $(NAME)
			

$(NAME):	$(OBJ) libft/libft.a
				@echo "$(MESSAGE_COMPILE)"
				@$(CC) $(CFLAGS) -g3 -Iinclude -Ilibft $(OBJ) -o $(NAME) -Llibft -lft
				@echo "$(MESSAGE_DONE)"


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

$(NAME_BONUS):	$(OBJ_BONUS) libft/libft.a
				@echo "$(MESSAGE_COMPILE)"
				@$(CC) $(CFLAGS) -g3 -Iinclude -Ilibft $(OBJ_BONUS) -o $(NAME_BONUS) -Llibft -lft
				@echo "$(MESSAGE_DONE)"

# END-BONUS -------------------------------------------

$(OBJDIR)/%.o:	%.c include/push_swap.h libft/libft.h | $(OBJDIR)
				@$(CC) $(CFLAGS) -g3 -Iinclude -Ilibft -c $< -o $@

$(OBJDIR):
				@mkdir -p $(OBJDIR)
				@mkdir -p $(OBJDIR)/commands
				@mkdir -p $(OBJDIR)/src

clean:
				@echo "$(MESSAGE_CLEAN)"
				@$(RM) -r $(OBJDIR)
				@echo "$(MESSAGE_CLEAN_DONE)"

fclean:	clean
				@$(RM) $(NAME)
				@$(RM) $(NAME_BONUS)
				@make fclean -C libft -s

force:
				@make -C libft -s

re:		fclean all

reb:	clean bonus

.PHONY:	all test bonus clean fclean force re reb
