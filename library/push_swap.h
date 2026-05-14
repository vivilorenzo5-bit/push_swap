/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlourenc <vlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:52:48 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/14 16:33:51 by vlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h> 
# include "../printfd/ft_printfd.h"
# include "../libft/libft.h"

typedef struct s_config
{
    int a_size;
    int b_size;
    int mode;
    int start_idx;
    int bench;
    int total;
    int ops[12];
}               t_config;

typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *prev;
    struct s_node   *next;
}               t_node;

t_config    *config_op(void);
double	    calculate_disorder(t_node *stack);
void        freesplit(char  **divide);
void        free_stack(t_node **stack);

int         flags_parsing(int ac, char **av, t_config *config);
int	        is_duplicate(t_node *stack, int value);
long	    convert_to_long(const char *str);
int	        valid_number(const char *str);
int	        divide_string(char *av, t_node **stack_a, t_config *config);

void	    sort_index(t_node **stack);

void        print_error(void);

int	        check_flag(char *av, t_config *config);
t_node	    *last_node(t_node *stack);
t_node	    *add_back(t_node **stack, int value);

#endif