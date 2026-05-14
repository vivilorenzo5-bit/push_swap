/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd_digits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-fon <roda-fon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:13:43 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/11 16:14:36 by roda-fon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

int	ft_print_nbr(int fd, int nbr)
{
	int		len;
	long	n;

	len = 0;
	n = nbr;
	if (n < 0)
	{
		len += ft_print_char(fd, '-');
		n = -n;
	}
	if (n > 9)
		len += ft_print_nbr(fd, n / 10);
	len += ft_print_char(fd, (n % 10) + '0');
	return (len);
}

int	ft_print_unsigned(int fd, unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr > 9)
		len += ft_print_unsigned(fd, nbr / 10);
	len += ft_print_char(fd, (nbr % 10) + '0');
	return (len);
}

int	ft_print_hex(int fd, unsigned long nbr, char *base)
{
	int				len;

	len = 0;
	if (nbr >= 16)
		len += ft_print_hex(fd, nbr / 16, base);
	len += ft_print_char(fd, base[nbr % 16]);
	return (len);
}
