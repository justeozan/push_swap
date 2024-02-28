/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:12:17 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/28 19:37:32 by ozasahin         ###   ########.fr       */
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
	while (stack)
	{
		if (stack->nbr == value)
			return (true);
		stack = stack->next;
	}
	return (false);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free2d(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_error(t_stack **a, char *err_txt, char **av, bool do_free)
{
	if (do_free)
		free2d(av);
	free_stack(a);
	ft_putstr_fd(err_txt, 2);
	exit(EXIT_FAILURE);
}
