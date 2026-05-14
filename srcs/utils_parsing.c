/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-fon <roda-fon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:00:23 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/12 15:15:53 by roda-fon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_flag(char *av, t_config *config)
{
	if (ft_strncmp(av, "--bench", 8) == 0
		|| ft_strncmp(av, "-b", 3) == 0)
		config->bench = 1;
	else if (ft_strncmp(av, "--simple", 9) == 0
		|| ft_strncmp(av, "-s", 3) == 0)
		config->mode = 1;
	else if (ft_strncmp(av, "--medium", 9) == 0
		|| ft_strncmp(av, "-m", 3) == 0)
		config->mode = 2;
	else if (ft_strncmp(av, "--complex", 10) == 0
		|| ft_strncmp(av, "-c", 3) == 0)
		config->mode = 3;
	else if (ft_strncmp(av, "--adaptive", 11) == 0
		|| ft_strncmp(av, "-a", 3) == 0)
		config->mode = 0;
	else if (ft_strncmp(av, "--total", 8) == 0
		|| ft_strncmp(av, "-t", 3) == 0)
		config->total = 1;
	else
		return (0);
	return (1);
}

static	t_node	*create_new_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_node	*last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_node	*add_back(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*back;

	new_node = create_new_node(value);
	if (!new_node)
		return (NULL);
	if (!*stack)
	{
		*stack = new_node;
		return (*stack);
	}
	back = last_node(*stack);
	back->next = new_node;
	new_node->prev = back;
	return (*stack);
}