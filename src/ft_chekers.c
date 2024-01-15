/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chekers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:58:23 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/15 15:14:24 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	check_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && i == 0)
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

bool	check_duplicate(t_stack *stack, int value)
{
	if (!stack)
		return (false);
	while (stack->next)
	{
		if (stack->nbr == value)
			return (true);
		stack = stack->next;
	}
	return (false);
}
