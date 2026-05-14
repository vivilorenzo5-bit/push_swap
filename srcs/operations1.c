/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlourenc <vlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:16:22 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/14 16:57:41 by vlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node *stack)
{
	int	temp_value;
	int	temp_index;

	if (!stack || !stack->next)
		return ;
	temp_value = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp_value;

	temp_index = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp_index;
}

void sa(t_node **a)
{
	swap(*a);
	write(1, "sa\n", 3);
}

void sb(t_node **b)
{
	swap(*b);
	write(1, "sb\n", 3);
}

static void push(t_node **dest, t_node **src)
{
	t_node *temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	temp->next = *dest;
	if (*dest)
		(*dest)->prev = temp;
	*dest = temp;
	(*dest)->prev = NULL;
}
