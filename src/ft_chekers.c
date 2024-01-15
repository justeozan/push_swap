/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chekers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:58:23 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/15 13:59:52 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

bool	check_duplicate(int value, t_stack *a)
{
	while (a->next)
	{
		if (a->nbr == value)
			return (true);
		a = a->next;
	}
	return (false);
}

