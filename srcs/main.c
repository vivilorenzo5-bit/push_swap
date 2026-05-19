/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlourenc <vlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:11:52 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/19 13:02:02 by vlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	av_validate(int ac, char **av, t_node **a, t_config *config)
{
    int     i;
    long    n;

    i = config->start_idx;
    while (i < ac)
    {
        if (valid_number(av[i]) == 0)
            return (0);
        n = convert_to_long(av[i]);
        if (n < INT_MIN || n > INT_MAX)
            return (0);
        if (is_duplicate(*a, (int)n) == 1)
            return (0);
        add_back(a, (int)n);
        if (!*a)
            return (0);
        config->a_size++;
        i++;
    }
    return (1);
}

static void execute_strategy(t_node **a, t_node **b, t_config *config)
{
    double disorder;

    sort_index(a);
    disorder = calculate_disorder(*a);
    if (config->mode == 0)
    {
        if (disorder < 0.2)
            simple_algorithm(a, b, config);
        else if (disorder >= 0.2 && disorder <= 0.5)
            medium_algorithm(a, b, config);
        else
            complex_algorithm(a, b, config);
    }
    else if (config->mode == 1)
        simple_algorithm(a, b, config);
    else if (config->mode == 2)
        medium_algorithm(a, b, config);
    else if (config->mode == 3)
        complex_algorithm(a, b, config);
}

static void	handle_outputs(t_config *config, double initial_disorder)
{
	if (config->bench == 1)
		print_benchmark(config, initial_disorder);
	else if (config->total == 1)
		ft_printfd(2, "%d\n", config->ops[0]);
}

int main(int ac, char **av)
{
    t_config	*config;
	t_node		*stack_a;
	t_node		*stack_b;
	double		init_disorder;

    if (ac < 2)
        return (0);
    stack_a = NULL;
    stack_b = NULL;
    config = config_op();
    if (!config || flags_parsing(ac, av, config) == -1)
        return (free(config), print_error(), 1);
	if (ac - config->start_idx < 1)
		return (free(config), print_error(), 0);
    if (ac - config->start_idx == 1)
    {
        if (!divide_string(av[config->start_idx], &stack_a, config))
            return (free(config), free_stack(&stack_a), print_error(), 0);
    }
    else if (!av_validate(ac, av, &stack_a, config))
        return (free(config), free_stack(&stack_a), print_error(), 0);
	init_disorder = calculate_disorder(stack_a);
	execute_strategy(&stack_a, &stack_b, config);
	handle_outputs(config, init_disorder);
	return (free_stack(&stack_a), free_stack(&stack_b), free(config), 0);
}
