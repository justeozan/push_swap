/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:09:06 by ozasahin          #+#    #+#             */
/*   Updated: 2024/01/15 13:58:44 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "commands.h"

typedef struct s_stack
{
	int		nbr;
	int		index;
	int		push_cost;
	bool	above_median;
	bool	cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}	t_stack;

/*---------ft_chekers.c---------*/

/*---------ft_errors.c---------*/
void	free_stack(t_stack **stack);
void	free2d(char **s);
void	ft_error(t_stack **a, char *err_txt, char **av, bool do_free);

/*---------push_swap.c---------*/
int		add_element_in_stack(t_stack **a, int n);
bool	check_syntax(char *str);
bool	check_duplicate(int value, t_stack *a);
void	init_stack(t_stack **stack, char **av, bool do_free);
int		main(int ac, char **av);


#endif
