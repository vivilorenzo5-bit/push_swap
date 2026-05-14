/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-fon <roda-fon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:13:52 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/11 16:14:07 by roda-fon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFD_H
# define FT_PRINTFD_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printfd(int fd, const char *format, ...);

int		ft_check_format(int fd, va_list argss, char format);
int		ft_print_str(int fd, char *str);
int		ft_print_char(int fd, int c);
int		ft_print_nbr(int fd, int nbr);
int		ft_print_unsigned(int fd, unsigned int nbr);
int		ft_print_hex(int fd, unsigned long nbr, char *base);
int		ft_print_ptr(int fd, unsigned long ptr);

#endif