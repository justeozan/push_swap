/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:12:37 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/17 16:45:36 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max_node;
	// int		max;

	if (!stack)
		return (NULL);
	max_node = stack;
	while (stack)
	{
		if (stack->nbr > max_node->nbr)
		{
			max_node = stack;
			// max = stack->nbr;
		}
		stack = stack->next;
	}
	return (max_node);
}
