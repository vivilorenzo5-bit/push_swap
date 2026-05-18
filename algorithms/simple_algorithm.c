/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlourenc <vlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:13:43 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/18 13:18:36 by vlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Encontra a posição (0, 1, 2...) do nó que tem o menor index na stack
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

// Roda a Stack A para trazer o menor elemento ao topo com o menor custo
static void	push_min_to_b(t_node **a, t_node **b, t_config *config)
{
	int	pos;
	int	half;

	pos = get_min_position(*a);
	half = config->a_size / 2;
	// Se estiver na primeira metade usamos ra
	if (pos <= half)
	{
		while (pos--)
			ra(a);
	}
	// Se estiver na segunda metade usamos rra
	else
	{
		pos = config->a_size - pos;
		while (pos--)
			rra(a);
	}
	pb(b, a);
	config->a_size--;
	config->b_size++;
}

void	simple_algorithm(t_node **a, t_node **b, t_config *config)
{
	// Esvazia a Stack A mandando sempre os menores para a B
	// até sobrarem apenas 3 elementos em A
	while (config->a_size > 3)
		push_min_to_b(a, b, config);
	// Ordena  os 3 que sobraram
	tiny_sort(a);
	// Devolve tudo de B para A que já vai entrar ordenado no topo
	while (config->b_size > 0)
	{
		pa(a, b);
		config->a_size++;
		config->b_size--;
	}
}
