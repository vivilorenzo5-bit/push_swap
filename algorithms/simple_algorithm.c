/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-fon <roda-fon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:57:43 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/20 12:11:10 by roda-fon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_position(t_node *stack)
{
	int	pos;
	int	min_pos;
	int	min_index;

	pos = 0;
	min_pos = 0;
	min_index = INT_MAX;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			min_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}

static void	push_min_to_b(t_node **a, t_node **b, t_config *config)
{
	int	pos;
	int	half;

	pos = get_min_position(*a);
	half = config->a_size / 2;
	if (pos <= half)
	{
		while (pos--)
			ra(a, config);
	}
	else
	{
		pos = config->a_size - pos;
		while (pos--)
			rra(a, config);
	}
	pb(a, b, config);
	config->a_size--;
	config->b_size++;
}

void	simple_algorithm(t_node **a, t_node **b, t_config *config)
{
	if (calculate_disorder(*a) == 0.0)
		return ;
	while (config->a_size > 3)
		push_min_to_b(a, b, config);
	tiny_sort(a, config);
	while (config->b_size > 0)
	{
		pa(a, b, config);
		config->a_size++;
		config->b_size--;
	}
}
