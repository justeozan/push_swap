/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:16:09 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/16 14:09:59 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*get_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	mv(t_stack **dst, t_stack **src, bool a_to_b)
{
	t_stack	*cheap;

	cheap = get_cheapest(*src);
	if (a_to_b)
	{
		if (cheap->above_median && cheap->target_node->above_median)
			rotate_both(dst, src, cheap, true);
		else if (!(cheap->above_median) && !(cheap->target_node->above_median))
			rev_rotate_both(dst, src, cheap, true);
		prep_for_push(src, cheap, 'a');
		prep_for_push(dst, cheap->target_node, 'b');
		pb(src, dst, true);
	}
	else
	{
		prep_for_push(dst, (*src)->target_node, 'a');
		pa(dst, src, true);
	}
}

void	min_on_top(t_stack **stack)
{
	t_stack	*min_node;

	min_node = find_max_or_min(*stack, false);
	if (!stack | !min_node)
		return ;
	while ((*stack)->nbr != min_node->nbr)
	{
		if (min_node->above_median)
			ra(stack, true);
		else
			rra(stack, true);
		min_node = find_max_or_min(*stack, false);
	}
}

void	find_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_node = stack;
	while (stack)
	{
		if (stack->push_cost < cheapest_node->push_cost)
			cheapest_node = stack;
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	cost_analyse(t_stack *a, int len_stack, int len_targ_stack)
{
	while (a)
	{
		a->push_cost = a->index;
		if (a->above_median == false)
			a->push_cost = len_stack - (a->index);
		if (a->target_node->above_median == true)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_targ_stack - (a->target_node->index);
		a = a->next;
	}
}
