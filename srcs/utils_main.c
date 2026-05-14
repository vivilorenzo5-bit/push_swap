/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-fon <roda-fon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:17:27 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/12 14:36:49 by roda-fon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_config    *config_op(void)
{
    t_config    *config;
    int         i;

    config = malloc(sizeof(t_config));
    if (!config)
        return (NULL);
    config->a_size = 0;
    config->b_size = 0;
    i = 0;
    while (i < 12)
    {
        config->ops[i] = 0;
        i++;
    }
    return (config);
}

double	calculate_disorder(t_node *stack)
{
    t_node  *i;
    t_node  *j;
    double  errors;
    double  pairs;

    if (!stack)
        return (0.0);
    pairs = 0;
    errors = 0;
    i = stack;
    while (i)
    {
        j = i->next;
        while (j)
        {
            pairs++;
            if (i->value > j->value)
                errors++;
            j = j->next;
        }
        i = i->next;
    }
    if (pairs == 0)
        return (0.0);
    return (errors / pairs);
}

void    freesplit(char  **divide)
{
    int i;

    if (!divide)
        return ;
    i = 0;
    while (divide[i])
    {
        free(divide[i]);
        i++;
    }
    free(divide);
}

void    free_stack(t_node **stack)
{
    t_node  *temp;

    if (!stack || !*stack)
        return ;
    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
    *stack = NULL;
}