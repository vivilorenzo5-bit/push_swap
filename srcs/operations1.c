/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlourenc <vlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:16:22 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/18 09:53:33 by vlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *stack)
{
	int	temp_value;
	int	temp_index;

	if (!stack || !stack->next)
		return ;
	temp_value = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp_value;

	temp_index = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp_index;
}

void	sa(t_node **a)
{
	swap(*a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap(*b);
	write(1, "sb\n", 3);
}

void	push(t_node **dest, t_node **src)
{
	t_node	*temp;

	if (!*src)
		return ;
	temp = *src; 				// Guarda o nó que vamos mover
	*src = (*src)->next;  		// O novo topo da origem passa a ser o segundo
	if (*src)
		(*src)->prev = NULL;	// Se sobrou alguém na origem, desliga o link para trás
	temp->next = *dest;			// O nó movido agora aponta para o antigo topo do destino
	if (*dest)
		(*dest)->prev = temp;	// O antigo topo do destino agora aponta para trás (para o novo nó)
	*dest = temp;				// O destino agora começa oficialmente no novo nó
	(*dest)->prev = NULL;		// Segurança: o topo nunca tem ninguém atrás
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}
