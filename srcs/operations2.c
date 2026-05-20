/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-fon <roda-fon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:16:35 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/20 10:47:43 by roda-fon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **a, t_node **b, t_config *config)
{
	push(b, a);
	write(1, "pb\n", 3);
	count_op(config, 5);
}

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = last_node(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_node **a, t_config *config)
{
	rotate(a);
	write(1, "ra\n", 3);
	count_op(config, 6);
}

void	rb(t_node **b, t_config *config)
{
	rotate(b);
	write(1, "rb\n", 3);
	count_op(config, 7);
}

void	rr(t_node **a, t_node **b, t_config *config)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	count_op(config, 8);
}
