/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-fon <roda-fon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:13:47 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/11 16:14:26 by roda-fon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

int	ft_print_str(int fd, char *str)
{
	int	count;

	if (!str)
		return (write(fd, "(null)", 6));
	count = 0;
	while (str[count])
	{
		write(fd, &str[count], 1);
		count++;
	}
	return (count);
}

int	ft_print_char(int fd, int c)
{
	return (write(fd, &c, 1));
}

int	ft_check_format(int fd, va_list args, char format)
{
	char	*base_up;
	char	*base;

	base_up = "0123456789ABCDEF";
	base = "0123456789abcdef";
	if (format == 'c')
		return (ft_print_char(fd, va_arg(args, int)));
	else if (format == 'd' || format == 'i')
		return (ft_print_nbr(fd, va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_unsigned(fd, va_arg(args, unsigned int)));
	else if (format == 's')
		return (ft_print_str(fd, va_arg(args, char *)));
	else if (format == 'x')
		return (ft_print_hex(fd, va_arg(args, unsigned int), base));
	else if (format == 'X')
		return (ft_print_hex(fd, va_arg(args, unsigned int), base_up));
	else if (format == 'p')
		return (ft_print_ptr(fd, va_arg(args, unsigned long)));
	else if (format == '%')
		return (ft_print_char(fd, '%'));
	return (0);
}
