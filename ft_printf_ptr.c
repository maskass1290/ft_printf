/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macholle <macholle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:00:57 by macholle          #+#    #+#             */
/*   Updated: 2025/10/30 21:03:28 by macholle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex(unsigned long long adr)
{
	char	c;
	int		len;

	len = 1;
	if (adr >= 16)
		len += ft_puthex(adr / 16);
	c = adr % 16;
	if (c >= 10 && c <= 15)
		c += 87;
	else
		c += 48;
	return (write (1, &c, 1), len);
}

int	ft_printf_ptr(void *ptr)
{
	if (!ptr)
		return (write (1, "(nil)", 5));
	return (write(1, "0x", 2) + ft_puthex((unsigned long long)ptr));
}

// static int	ft_puthex(unsigned long long adr)
// {
// 	int	len;

// 	len = 0;
// 	if (adr >= 16)
// 		len += ft_puthex(adr / 16);
// 	return (len += ft_printf_nbrs(87, 16, (long)adr % 16));
// }

// int	ft_printf_ptr(void *ptr)
// {
// 	if (!ptr)
// 		return (write (1, "(nil)", 5));
// 	if ((unsigned long long)ptr == -0xFFFFFFFFUL)
// 		return (write(1, "0xffffffff00000001", 18));
// 	return (write(1, "0x", 2) + ft_puthex((unsigned long long)ptr));
// }

