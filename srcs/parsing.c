/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-fon <roda-fon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:59:19 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/12 15:25:46 by roda-fon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int flags_parsing(int ac, char **av, t_config *config)
{
    int i;

    i = 1;
    while (i < ac)
    {
        if (av[1][0] == '-')
        {
            if (av[i][1] == '\0' || (av[i][1] >= '0' && av[i][1] <= '9'))
                break ;
            if (check_flag(av[i], config) == 0)
                return (-1);
            i++;
        }
        else
            break ;
    }
    return (i);
}

int	divide_string(char *av, t_node **stack_a, t_config *config)
{
    char    **args_split;
    int     i;
    long    n;

    args_split = ft_split(av, ' ');
    if (!args_split || !*args_split)
        return (freesplit(args_split), 0);
    i = 0;
    while (args_split[i])
    {
        if (!valid_number(args_split[i]))
            return (freesplit(args_split), 0);
        n = convert_to_long(args_split[i]);
        if (n < INT_MIN || n > INT_MAX)
            return (freesplit(args_split), 0);
        if (is_duplicate(*stack_a, (int)n))
            return (freesplit(args_split), 0);
        *stack_a = add_back(stack_a, (int)n);
        if (!*stack_a)
            return (freesplit(args_split), 0);
        config->a_size++;
        i++;
    }
    return (freesplit(args_split), 1);
}

int	valid_number(const char *str)
{
    int i;

    if (!str || !*str)
        return (0);
    i = 0;
    if (str[i] == '-' || str[i] == '+')
        if (!str[i++])
            return (0);
    while (str[i])
    {
        if (!str[i] >= '0' && str[i] <= '9')
            return (0);
        i++;
    }
    return (1);
}

long	convert_to_long(const char *str)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	is_duplicate(t_node *stack, int value)
{
    t_node  *i;

    i = stack;
    while (i)
    {
        if (i->value == value)
            return (1);
        i = i->next;
    }
    return (0);
}