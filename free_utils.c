/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlourenc <vlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:29:44 by vlourenc          #+#    #+#             */
/*   Updated: 2026/05/13 13:19:26 by vlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*curr;

	if (!stack)
		return ;
	curr = *stack;
	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	*stack = NULL;
}

void	free_argv(char **argv)
{
	int i;

	i = 0;
	if (!argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	free_errors(t_stack_node **a, char **argv, bool issplit)
{
	free_stack(a);
	if (issplit)
		free_argv(argv);
	write(2, "Error\n", 6);
	exit(1);
}
