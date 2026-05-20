/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tatic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-fon <roda-fon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:37:08 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/19 14:07:38 by roda-fon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_index(t_node **stack)
{
	t_node	*atual;
	t_node	*i;
	int		smaller;

	if (!stack || !*stack)
		return ;
	i = *stack;
	while (i)
	{
		smaller = 0;
		atual = *stack;
		while (atual)
		{
			if (i->value > atual->value
				|| (i->value == atual->value && i > atual))
				smaller++;
			atual = atual->next;
		}
		i->index = smaller;
		i = i->next;
	}
}

static int	find_max_index(t_node *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	tiny_sort(t_node **a, t_config *config)
{
	int	maxindex;

	if (!a || !*a || !(*a)->next)
		return ;
	maxindex = find_max_index(*a);
	if ((*a)->index == maxindex)
		ra(a, config);
	else if ((*a)->next->index == maxindex)
		rra(a, config);
	if ((*a)->index > (*a)->next->index)
		sa(a, config);
}
