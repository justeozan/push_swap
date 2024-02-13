/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:58:23 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/12 19:45:54 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	do_commands(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(stack_a, false);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stack_b, false);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b, false);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(stack_a, stack_b, false);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b, false);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(stack_a, false);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stack_b, false);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b, false);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stack_a, false);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stack_b, false);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b, false);
	else
		return (0);
	return (1);
}

void	checker_result(t_stack **a, t_stack **b)
{
	if (stack_is_sorted(*a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (*a)
		free_stack(a);
	if (*b)
		free_stack(b);
}

int	main(int ac, char **av)
{
	char	*line;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	else if (ac == 2)
		init_stack(&a, ft_split(av[1], ' '), true); // Juste renvoyer Error
	else
		init_stack(&a, av + 1, false); // Juste renvoyer Error
	line = get_next_line(0);
	while (line != NULL)
	{
		if (do_commands(line, &a, &b) == 0)
		{
			free_stack(&b); // + free line
			ft_error(&a, "Error", NULL, false); // Juste renvoyer Error
		}
		free(line);
		line = get_next_line(0);
	}
	checker_result(&a, &b);// + free line
	return (0);
}
