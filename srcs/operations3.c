/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlourenc <vlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 10:11:33 by vlourenc          #+#    #+#             */
/*   Updated: 2026/05/18 11:25:13 by vlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_node **stack)
{
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
	last->prev->next = NULL; // O penúltimo agora diz que a seguir a ele é NULL
	last->next = *stack; // antigo ultimo passa a apontar para o antigo topo
	(*stack)->prev = last; // antigo topo aponta para tras
	last->prev = NULL; // o topo nao tem ninguem atras
	*stack = last; // atualiza o ponteiro real da stack
}

void	rra(t_node **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
