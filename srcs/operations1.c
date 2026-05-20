/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-fon <roda-fon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:16:22 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/20 10:46:59 by roda-fon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *stack)
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

void	sa(t_node **a, t_config *config)
{
	swap(*a);
	write(1, "sa\n", 3);
	count_op(config, 1);
}

void	sb(t_node **b, t_config *config)
{
	swap(*b);
	write(1, "sb\n", 3);
	count_op(config, 2);
}

void	push(t_node **dest, t_node **src)
{
	t_node	*temp;

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

void	pa(t_node **a, t_node **b, t_config *config)
{
	push(a, b);
	write(1, "pa\n", 3);
	count_op(config, 4);
}
