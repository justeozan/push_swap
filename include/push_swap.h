/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:09:06 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/23 09:42:12 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}	t_stack;

# include "commands.h"

/***************SRC****************/
/*---------ft_chekers.c---------*/
bool	check_syntax(char *str);
bool	check_duplicate(t_stack *a, int value);
/*---------ft_errors.c---------*/
void	free_stack(t_stack **stack);
void	free2d(char **s);
void	ft_error(t_stack **a, char *err_txt, char **av, bool do_free);
/*---------ft_sort_utils.c---------*/
t_stack	*get_cheapest(t_stack *stack);
void	mv(t_stack **dst, t_stack **src, bool a_to_b);
void	min_on_top(t_stack **stack);
void	find_cheapest(t_stack *stack);
void	cost_analyse(t_stack *a, int len_stack, int len_targ_stack);
/*---------ft_stack_utils.c---------*/
void	prep_for_push(t_stack **stack, t_stack *top_node, char name);
t_stack	*find_last(t_stack *stack);
bool	stack_is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
t_stack	*find_max_or_min(t_stack *stack, bool true_for_max);
/*---------push_swap.c---------*/
void	sort_three(t_stack **stack);
int		add_element_in_stack(t_stack **stack, int n);
void	init_stack(t_stack **stack, char **av, bool do_free);
int		main(int ac, char **av);
/*---------sort_stack.c---------*/
void	set_target_a(t_stack *stack, t_stack *target_stack, bool true_for_max);
void	set_target_b(t_stack *stack, t_stack *target_stack, bool true_for_max);
void	init_id(t_stack *stack);
void	set_stack(t_stack *a, t_stack *b, char stack_name);
void	sort_stack(t_stack **a, t_stack **b, int size_stack_a, int round);

#endif
