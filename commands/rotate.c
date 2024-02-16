/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:06:20 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/16 15:52:10 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_both(t_stack **st1, t_stack **st2, t_stack *cheap, bool print)
{
	while (*st2 != cheap && *st1 != cheap->target_node)
		rr(st1, st2, print);
	init_id(*st1);
	init_id(*st2);
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
	{
		free_stack(stack);
		return ;
	}
	first = (*stack);
	(*stack) = (*stack)->next;
	last = find_last(*stack);
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **a, bool print)
{
	rotate(a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool print)
{
	rotate(b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
}
