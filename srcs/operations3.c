/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-fon <roda-fon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:30:11 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/20 10:48:05 by roda-fon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_node **stack)
{
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	last->prev = NULL;
	*stack = last;
}

void	rra(t_node **a, t_config *config)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
	count_op(config, 9);
}

void	rrb(t_node **b, t_config *config)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
	count_op(config, 10);
}

void	rrr(t_node **a, t_node **b, t_config *config)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
	count_op(config, 11);
}

void	ss(t_node **a, t_node **b, t_config *config)
{
	swap(*a);
	swap(*b);
	write(1, "ss\n", 3);
	count_op(config, 3);
}
