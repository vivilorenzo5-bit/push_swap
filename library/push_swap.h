/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-fon <roda-fon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:52:48 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/20 10:45:46 by roda-fon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_config
{
	int				a_size;
	int				b_size;
	int				mode;
	int				start_idx;
	int				bench;
	int				total;
	int				ops[12];
}					t_config;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

int			main(int ac, char **av);
void		count_op(t_config *config, int i);

int			ft_printfd(int fd, const char *format, ...);
int			ft_check_format(int fd, va_list argss, char format);
int			ft_print_str(int fd, char *str);
int			ft_print_char(int fd, int c);
int			ft_print_nbr(int fd, int nbr);
int			ft_print_unsigned(int fd, unsigned int nbr);
int			ft_print_hex(int fd, unsigned long nbr, char *base);
int			ft_print_ptr(int fd, unsigned long ptr);

int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_split(char const *s, char c);

t_config	*config_op(void);
double		calculate_disorder(t_node *stack);
void		freesplit(char **divide);
void		free_stack(t_node **stack);

int			flags_parsing(int ac, char **av, t_config *config);
int			is_duplicate(t_node *stack, int value);
long		convert_to_long(const char *str);
int			valid_number(const char *str);
int			divide_string(char *av, t_node **stack_a, t_config *config);

void		sort_index(t_node **stack);
void		tiny_sort(t_node **a, t_config *config);

void		simple_algorithm(t_node **a, t_node **b, t_config *config);
void		medium_algorithm(t_node **a, t_node **b, t_config *config);
void		complex_algorithm(t_node **a, t_node **b, t_config *config);

void		print_error(void);
void		print_benchmark(t_config *config, double disorder);

int			check_flag(char *av, t_config *config);
t_node		*last_node(t_node *stack);
t_node		*add_back(t_node **stack, int value);

void		swap(t_node *stack);
void		sa(t_node **a, t_config *config);
void		sb(t_node **b, t_config *config);
void		ss(t_node **a, t_node **b, t_config *config);
void		push(t_node **dest, t_node **src);
void		pa(t_node **a, t_node **b, t_config *config);
void		pb(t_node **a, t_node **b, t_config *config);
void		rotate(t_node **stack);
void		ra(t_node **a, t_config *config);
void		rb(t_node **b, t_config *config);
void		rr(t_node **a, t_node **b, t_config *config);
void		rev_rotate(t_node **stack);
void		rra(t_node **a, t_config *config);
void		rrb(t_node **b, t_config *config);
void		rrr(t_node **a, t_node **b, t_config *config);

#endif
