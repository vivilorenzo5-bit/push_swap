/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlourenc <vlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 18:21:49 by vlourenc          #+#    #+#             */
/*   Updated: 2026/05/13 11:22:48 by vlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h> 
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				currpos;
	int				pushcost;
	bool			above_median;
	bool			cheapest;

	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}	t_stack_node;

#endif