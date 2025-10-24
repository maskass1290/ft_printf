/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macholle <macholle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:00:57 by macholle          #+#    #+#             */
/*   Updated: 2025/10/24 15:30:53 by macholle         ###   ########.fr       */
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
	write (1, &c, 1);
	return (len);
}

int	ft_printf_ptr(void *ptr)
{
	unsigned long long	adr;

	if (!ptr)
		return (write (1, "(nil)", 5));
	adr = (unsigned long long)ptr;
	return (write(1, "0x", 2) + ft_puthex(adr));
}
