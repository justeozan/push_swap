/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:16:09 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/18 17:12:07 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void	mv_ab();
// void	mv_ba();
// void	min_on_top();
// void	cost_analyse();
// void	find_cheapest();

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
			rotate_both(dst, src, cheap, false);
		else if (!(cheap->above_median) && !(cheap->target_node->above_median))
			rotate_both(dst, src, cheap, true);
		prep_for_push(src, cheap, 'a');
		prep_for_push(dst, cheap->target_node, 'b');
		pb(src, dst);
	}
	else
	{
		prep_for_push(dst, (*src)->target_node, 'a');
		pa(dst, src);
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
		// if ((*stack)->above_median)
		if (min_node->above_median)
			ra(stack);
		else
			rra(stack);
		min_node = find_max_or_min(*stack, false);
	}
}

// void min_on_top(t_stack **a)
// {
//     while (1)
//     {
//         t_stack *minNode = find_max_or_min(*a,false);

//         if (!minNode) // Si la liste est vide, il n'y a rien à faire.
//             return;

//         if ((*a)->nbr == minNode->nbr) // Si le minimum est déjà en haut, nous avons terminé.
//             break;

//         // Le minimum n'est pas en haut, donc nous devons décider d'utiliser ra ou rra.
//         if (minNode->above_median)
//             ra(a);
//         else
//             rra(a);
//     }
// }

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
