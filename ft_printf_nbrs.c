/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macholle <macholle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:59:44 by macholle          #+#    #+#             */
/*   Updated: 2025/10/24 15:30:53 by macholle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_nbrs(int fd, int dvsr, long nb)
{
	char	c;
	int		i;

	i = 1;
	if (nb < 0)
	{
		nb *= -1;
		i += write(1, "-", 1);
	}
	if (nb >= dvsr)
		i += ft_printf_nbrs(fd, dvsr, nb / dvsr);
	c = (nb % dvsr);
	if (c <= 15 && c >= 10)
		c += fd;
	else
		c += 48;
	write (1, &c, 1);
	return (i);
}
