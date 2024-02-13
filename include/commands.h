/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:57:14 by ozasahin          #+#    #+#             */
/*   Updated: 2024/02/13 15:18:30 by ozasahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "push_swap.h"

/*************COMMANDS**************/
/*---------push.c---------*/
void	push(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **a, t_stack **b, bool print);
/*---------rev_rotate.c---------*/
void	rev_rotate_both(t_stack **s1, t_stack **s2, t_stack *cheap, bool print);
void	rev_rotate(t_stack **stack);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);
/*---------rotate.c---------*/
void	rotate_both(t_stack **st1, t_stack **st2, t_stack *cheap, bool print);
void	rotate(t_stack **stack);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
/*---------swap.c---------*/
void	swap(t_stack **stack);
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);

#endif