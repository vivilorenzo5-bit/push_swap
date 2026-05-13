/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlourenc <vlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 18:50:46 by vlourenc          #+#    #+#             */
/*   Updated: 2026/05/13 12:26:56 by vlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	node->cheapest = false;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	stack_init_a(t_stack_node **a, char **argv, bool is_split)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		if (syntax_error(argv[i]))
			free_errors(a, argv, is_split);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a, argv, is_split);
		if (error_duplicate(*a, (int)n))
			free_errors(a, argv, is_split);
		append_node(a, (int)n);
		i++;
	}
	if (is_split)
		free_argv(argv);
}
