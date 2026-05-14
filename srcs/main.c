/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-fon <roda-fon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:11:52 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/14 12:51:29 by roda-fon         ###   ########.fr       */
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

static void	valid_stack(t_config *config, t_node **a, t_node **b)
{
    double  disorder;

    if (config->a_size > 0)
    {
        disorder = calculate_disorder(*a);
        
    }
}

int main(int ac, char **av)
{
    t_config	*config;
	t_node		*stack_a;
	t_node		*stack_b;
    
    if (ac < 2)
        return (0);
    stack_a = NULL;
    stack_b = NULL;
    config = config_op();
    if (!config)
        return (1);
    config->start_idx = flags_parsing(ac, av, config);
    if (config->start_idx == -1 || ac - config->start_idx < 1)
        return (free(config), print_error(), 0);
    if (ac - config->start_idx == 1)
    {
        if (!divide_string(av[config->start_idx], &stack_a, config))
            return (free(config), free_stack(&stack_a), print_error(), 0);
    }
    else if (!av_validate(ac, av, &stack_a, config))
        return (freesplit(config), free_stack(&stack_a), print_error(), 0);
    ...;
    if (config->total == 1)
        ft_printfd(1, "%d\n", config->ops[0]);
    return (0);
}