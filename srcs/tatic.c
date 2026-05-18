/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tatic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlourenc <vlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:57:43 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/18 11:47:34 by vlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	tiny_sort(t_node **a)
{
	int	maxindex;

	if (!a || !*a || !(*a)->next)
		return ;
	maxindex = find_max_index(*a);
	if ((*a)->index == maxindex)
		ra(a);
	else if ((*a)->next->index == maxindex)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(*a);
}

void	sort_index(t_node **stack)
{
    t_node  *atual;
    t_node  *i;
    int     smaller;
    
    if (!stack || !*stack)
        return (NULL);
    i = *stack;
    while (i)
    {
        smaller = 0;
        atual = *stack;
        while (atual)
        {
            if (i->value > atual->value
            || i->value == atual->value && i > atual)
                smaller++;
            atual = atual->next;
        }
        i->index = smaller;
        i = i->next;
    }
}