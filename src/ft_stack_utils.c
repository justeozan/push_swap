/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:12:37 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/12 19:49:39 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	prep_for_push(t_stack **stack, t_stack *top_node, char name)
{
	if (!(*stack) || !top_node || (name != 'a' && name != 'b'))
		return ;
	while ((*stack) != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_median == true)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

bool	stack_is_sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

// t_stack	*find_max(t_stack *stack)
// {
// 	t_stack	*max_node;

// 	if (!stack)
// 		return (NULL);
// 	max_node = stack;
// 	while (stack)
// 	{
// 		if (stack->nbr > max_node->nbr)
// 		{
// 			max_node = stack;
// 		}
// 		stack = stack->next;
// 	}
// 	return (max_node);
// }

t_stack	*find_max_or_min(t_stack *stack, bool true_for_max)
{
	t_stack	*extrem_node;

	if (!stack)
		return (NULL);
	extrem_node = stack;
	while (stack)
	{
		if ((true_for_max == true && stack->nbr > extrem_node->nbr)
			|| (true_for_max == false && stack->nbr < extrem_node->nbr))
			extrem_node = stack;
		stack = stack->next;
	}
	return (extrem_node);
}
