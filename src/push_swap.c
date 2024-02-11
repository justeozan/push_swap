/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:09:21 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/11 18:01:00 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*max;

	if (!(*stack))
		return ;
	max = find_max_or_min(*stack, true);
	if ((*stack) == max)
		ra(stack);
	else if ((*stack)->next == max)
		rra(stack);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack);
}

int	add_element_in_stack(t_stack **stack, int n)
{
	t_stack	*new;
	t_stack	*last_node;

	if (!stack)
		return (-1);
	new = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!new)
		return (-1);
	new->next = NULL;
	new->nbr = n;
	if (!(*stack))
		(*stack) = new;
	else
	{
		last_node = find_last(*stack);
		last_node->next = new;
	}
	return (1);
}

void	init_stack(t_stack **stack, char **av, bool do_free)
{
	int		i;
	long	n;

	i = 0;
	while (av[i])
	{
		if (!check_syntax(av[i]))
			ft_error(stack, "\nERROR : bad syntax\n", av, do_free);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_error(stack, "\nERROR : bad value", av, do_free);
		if (check_duplicate(*stack, n))
			ft_error(stack, "\nERROR : number two times", av, do_free);
		if (!add_element_in_stack(stack, (int)n))
			ft_error(stack, "\nERROR : problem adding to stack", av, do_free);
		i++;
	}
	if (do_free)
		free2d(av);
}
