/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-fon <roda-fon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:50:59 by roda-fon          #+#    #+#             */
/*   Updated: 2026/05/20 10:42:36 by roda-fon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/push_swap.h"

static int	ft_print_ptr_hex(int fd, unsigned long ptr)
{
	char	*base;
	int		len;

	base = "0123456789abcdef";
	len = 0;
	if (ptr >= 16)
		len += ft_print_ptr_hex(fd, ptr / 16);
	write(fd, &base[ptr % 16], 1);
	len++;
	return (len);
}

int	ft_print_ptr(int fd, unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (write(fd, "(nil)", 5));
	write(fd, "0x", 2);
	len += 2;
	len += ft_print_ptr_hex(fd, ptr);
	return (len);
}
