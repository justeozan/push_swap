/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:06:20 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/18 16:14:54 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_both(t_stack **st1, t_stack **st2, t_stack *cheap, bool rev)
{
	if (!rev)
		while (*st2 != cheap && *st1 != cheap->target_node)
			rr(st1, st2);
	else
		while (*st2 != cheap && *st1 != cheap->target_node)
			rrr(st1, st2);
	init_id(*st1);
	init_id(*st2);
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack)
		return ;
	first = (*stack);
	(*stack) = (*stack)->next;
	last = find_last(*stack);
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
