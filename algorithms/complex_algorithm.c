/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlourenc <vlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:13:39 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/19 11:56:34 by vlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_index)
{
	int	bits;

	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

static void	sort_bit_layer(t_node **a, t_node **b, t_config *config, int i)
{
	int	j;
	int	size;

	j = 0;
	size = config->a_size;
	while (j < size)
	{
		if ((((*a)->index >> i) & 1) == 1)
			ra(a);
		else
		{
			pb(b, a);
			config->b_size++;
		}
		j++;
	}
}

void	complex_algorithm(t_node **a, t_node **b, t_config *config)
{
	int	i;
	int	max_bits;

	i = 0;
	max_bits = get_max_bits(config->a_size - 1);
	while (i < max_bits)
	{
		sort_bit_layer(a, b, config, i);
		while (config->b_size > 0)
		{
			pa(a, b);
			config->b_size--;
		}
		i++;
	}
}
