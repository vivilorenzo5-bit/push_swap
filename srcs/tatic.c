/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tatic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-fon <roda-fon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:57:43 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/14 14:20:36 by roda-fon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_index(t_node **stack)
{
    t_node  *atual;
    t_node  *i;
    int     smaller;
    
    if (!stack || !*stack)
        return (NULL);
    i = *stack;
    while (i)
    {
        smaller = 0;
        atual = *stack;
        while (atual)
        {
            if (i->value > atual->value
            || i->value == atual->value && i > atual)
                smaller++;
            atual = atual->next;
        }
        i->index = smaller;
        i = i->next;
    }
}