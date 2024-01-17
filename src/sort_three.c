/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:41:24 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/17 09:11:28 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack *max;

	if (!(*stack))
		return ;
	max = find_max(*stack);
	if ((*stack) == max)
		ra(stack);
	else if ((*stack)->next == max)
		rra(stack);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack);
}