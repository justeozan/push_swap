/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:06:18 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/15 17:18:51 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack **a, bool print)
{
	t_stack *tmp;
	
	if (!a || stack_size(a) < 2)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (print)
		write(1, "sb\n", 3);
}

void	sb(t_stack **b, bool print)
{
	if (stack_size(b) < 2)
		return ;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, false);
	sb(b, false);
	write(1, "ss\n", 3);
}