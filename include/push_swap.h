/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:09:06 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/15 17:14:51 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "commands.h"

typedef struct s_stack
{
	int		nbr;
	int		index;
	int		push_cost;
	bool	above_median;
	bool	cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}	t_stack;

/*************COMMANDS**************/
/*---------push.c---------*/
void	push(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
/*---------swap.c---------*/
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b);
/***************SRC****************/
/*---------ft_stack_utils.c---------*/
t_stack	*find_last(t_stack *stack);
bool	stack_is_sorted(t_stack *stack);
int	stack_size(t_stack *stack);
/*---------ft_chekers.c---------*/
bool	check_syntax(char *str);
bool	check_duplicate(t_stack *a, int value);
/*---------ft_errors.c---------*/
void	free_stack(t_stack **stack);
void	free2d(char **s);
void	ft_error(t_stack **a, char *err_txt, char **av, bool do_free);
/*---------push_swap.c---------*/
int		add_element_in_stack(t_stack **stack, int n);
void	init_stack(t_stack **stack, char **av, bool do_free);
int		main(int ac, char **av);

#endif
