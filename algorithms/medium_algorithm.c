/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlourenc <vlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:12:39 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/19 11:03:30 by vlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sqrt(int number)
{
	int	i;

	i = 1;
	while (i * i <= number)
		i++;
	return (i - 1);
}

static void	handle_pb_rotate(t_node **a, t_node **b, int min, int max)
{
	pb(b, a);
	if ((*b)->index < (min + max) / 2)
		rb(b);
}

static void	push_chunks_to_b(t_node **a, t_node **b, t_config *config)
{
	int	chunk_size;
	int	min_limit;
	int	max_limit;

	chunk_size = (config->a_size / sqrt(config->a_size)) + 1;
	min_limit = 0;
	max_limit = chunk_size;
	while (*a)
	{
		if ((*a)->index >= min_limit && (*a)->index < max_limit)
		{
			handle_pb_rotate(a, b, min_limit, max_limit);
			config->a_size--;
			config->b_size++;
		}
		else
			ra(a);
		if (config->b_size >= max_limit)
		{
			min_limit = max_limit;
			max_limit += chunk_size;
		}
	}
}

static void	push_max_to_a(t_node **a, t_node **b, t_config *config)
{
	int		pos;
	int		target;
	t_node	*tmp;

	pos = 0;
	target = config->b_size - 1;
	tmp = *b;
	while (tmp && tmp->index != target)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= config->b_size / 2)
	{
		while ((*b)->index != target)
			rb(b);
	}
	else
	{
		while ((*b)->index != target)
		{
			rrb(b);
		}
	}
	pa(a, b);
}

void	medium_algorithm(t_node **a, t_node **b, t_config *config)
{
	push_chunks_to_b(a, b, config);
	while (config->b_size > 0)
	{
		push_max_to_a(a, b, config);
		config->a_size++;
		config->b_size--;
	}
}
