/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:51:20 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/18 16:38:00 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// t_stack	*find_max_or_min(t_stack *stack, char stack_name)
// {
// 	t_stack *max_or_min_node;

// 	max_or_min_node = NULL;
// 	if (stack_name == 'a')
// 		max_or_min_node = find_max(stack);
// 	else if (stack_name == 'b')
// 		max_or_min_node = find_min(stack);
// 	return (max_or_min_node);
// }

void	set_target_b(t_stack *stack, t_stack *target_stack, bool true_for_max)
{
	t_stack	*cur_targ_stack;
	t_stack	*target_node;
	int		max;

	if (!stack || !target_stack)
		return ;
	while (stack)
	{
		cur_targ_stack = target_stack;
		max = INT_MAX;
		while (cur_targ_stack)
		{
			if (cur_targ_stack->nbr > stack->nbr && cur_targ_stack->nbr < max)
			{
				max = cur_targ_stack->nbr;
				target_node = cur_targ_stack;
			}
			cur_targ_stack = cur_targ_stack->next;
		}
		if (max == INT_MAX)
			stack->target_node = find_max_or_min(target_stack, true_for_max);
		else
			stack->target_node = target_node;
		stack = stack->next;
	}
}

void	set_target(t_stack *stack, t_stack *target_stack, bool true_for_max)
{
	t_stack	*cur_targ_stack;
	t_stack	*target_node;
	int		max;

	if (!stack || !target_stack)
		return ;
	while (stack)
	{
		cur_targ_stack = target_stack;
		max = INT_MIN;
		while (cur_targ_stack)
		{
			if (cur_targ_stack->nbr < stack->nbr && cur_targ_stack->nbr > max)
			{
				max = cur_targ_stack->nbr;
				target_node = cur_targ_stack;
			}
			cur_targ_stack = cur_targ_stack->next;
		}
		if (max == INT_MIN)
			stack->target_node = find_max_or_min(target_stack, true_for_max);
		else
			stack->target_node = target_node;
		stack = stack->next;
	}
}

void	init_id(t_stack *stack)
{
	int	median;
	int	i;

	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i++;
		if (stack->index > median)
			stack->above_median = false;
		else
			stack->above_median = true;
		stack = stack->next;
	}
}

void	set_stack(t_stack *a, t_stack *b, char stack_name)
{
	if (stack_name == 'a')
	{
		init_id(a);
		init_id(b);
		set_target(a, b, true);
		cost_analyse(a, stack_size(a), stack_size(b));
		find_cheapest(a);
	}
	else if (stack_name == 'b')
	{
		init_id(a);
		init_id(b);
		set_target_b(b, a, false);
	}
}

void	sort_stack(t_stack **a, t_stack **b, int size_stack_a, int round)
{
	while (!stack_is_sorted(*a) && size_stack_a-- > 3)
	{
		if (round++ < 2)
			pb(a, b);
		else
		{
			set_stack(*a, *b, 'a');
			// mv_ab(a, b);
			mv(b, a, true);
		}
	}
	sort_three(a);
	while (*b)
	{
		set_stack(*a, *b, 'b');
		// mv_ba(a, b);
		mv(a, b, false);
	}
	init_id(*a);
	min_on_top(a);
}
