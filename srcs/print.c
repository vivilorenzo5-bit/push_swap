/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-fon <roda-fon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:56:56 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/19 14:13:34 by roda-fon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_printfd(2, "Error\n");
}

static void	print_strategy(t_config *config, double disorder)
{
	if (config->mode == 0)
	{
		ft_printfd(2, "Adaptive / ");
		if (disorder < 0.2)
			ft_printfd(2, "O(n^2)\n");
		else if (disorder < 0.5)
			ft_printfd(2, "O(n√n)\n");
		else
			ft_printfd(2, "O(n log n)\n");
	}
	else if (config->mode == 1)
		ft_printfd(2, "Simple / O(n^2)\n");
	else if (config->mode == 2)
		ft_printfd(2, "Medium / O(n√n)\n");
	else if (config->mode == 3)
		ft_printfd(2, "Complex / O(n log n)\n");
}

void	print_benchmark(t_config *config, double disorder)
{
	ft_printfd(2, "[bench] disorder: %d%%\n", (int)(disorder * 100));
	ft_printfd(2, "[bench] strategy: ");
	print_strategy(config, disorder);
	ft_printfd(2, "[bench] total_ops: %d\n", config->ops[0]);
	ft_printfd(2,
		"[bench] sa:%d sb:%d ss:%d pa:%d pb:%d\n",
		config->ops[1],
		config->ops[2],
		config->ops[3],
		config->ops[4],
		config->ops[5]);
	ft_printfd(2,
		"[bench] ra:%d rb:%d rr:%d rra:%d rrb:%d rrr:%d\n",
		config->ops[6],
		config->ops[7],
		config->ops[8],
		config->ops[9],
		config->ops[10],
		config->ops[11]);
}
