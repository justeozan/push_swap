/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:16:09 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/18 11:47:53 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void	mv_ab();
// void	mv_ba();
// void	min_on_top();
// void	cost_analyse();
// void	find_cheapest();

void	find_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_node = stack;
	while (stack)
	{
		if (stack->push_cost < cheapest_node->push_cost)
			cheapest_node = stack->push_cost;
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
			a->push_cost += len_targ_stack - (a->target_node->next);
		a = a->next;
	}
}
