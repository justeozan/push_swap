/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:51:20 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/17 16:45:21 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



void	init_id(t_stack *stack)
{
	int	i;

	if (!stack)
		return ;
	i = 0;
	while (stack)
	{
		stack->index = i++;
		stack = stack->next;
	}
}


void	set_stack(t_stack *a, t_stack *b, char stack_name)
{
	if (stack_name == 'a')
	{
		init_id(a);
		init_id(b);
		set_target_stack_a(a, b);
		cost_analyse(a, b);
		find_cheapest(a);
	}
	else if (stack_name == 'b')
	{
		init_id(a);
		init_id(b);
		set_target_stack_b(a, b);
	}
}

void	sort_stack(t_stack **a, t_stack **b, int size_stack_a, int round)
{
	while (!stack_is_sorted(&a) && size_stack_a-- > 3)
	{
		if (round++ < 2)
			pb(a, b);
		else
		{
			set_stack(*a, *b, 'a');
			mv_ab(a, b);
		}
	}
	sort_three(a);
	while (*b)
	{
		set_stack(*a, *b, 'b');
		mv_ba(a, b);
	}
	init_id(*a);
	min_on_top(a);
}
