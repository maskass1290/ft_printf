/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macholle <macholle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:12:13 by macholle          #+#    #+#             */
/*   Updated: 2025/10/24 16:07:37 by macholle         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(char *c)
{
	int	i;

	if (!c)
		return (write(1, "(null)", 6));
	i = 0;
	while (c[i])
		write(1, &c[i++], 1);
	return (i);
}
