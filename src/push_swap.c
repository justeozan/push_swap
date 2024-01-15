/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:09:21 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/15 16:36:21 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



int	add_element_in_stack(t_stack **stack, int n)
{
	t_stack *new;
	t_stack *last_node;

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
			ft_error(stack, "\nERROR : a number is present several times", av, do_free);
		if (!add_element_in_stack(stack, (int)n))
			ft_error(stack, "\nERROR : problem when adding to the stack", av, do_free);
		i++;
	}
	if (do_free)
		free2d(av);
}

int main(int ac, char **av)
{
	t_stack *a;
	// t_stack *b;
	
	a = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	else if (ac == 2)
		init_stack(&a, ft_split(av[1], ' '), true);
	else
		init_stack(&a, av + 1, false);
	if (!stack_is_sorted(a))
	{
		ft_putstr_fd("not sorted\n", 2);
		ft_printf("stack size = %d\n", stack_size(a));
		if (stack_size(a) == 2)
			return (0);
		else if (stack_size(a) == 3)
			return (0);
		else
			ft_putstr_fd("size is more than 3 numbers\n", 2);
		
		return (0);
	}
	ft_putstr_fd("sorted\n", 2);
	free_stack(&a);
	return (0);
}
