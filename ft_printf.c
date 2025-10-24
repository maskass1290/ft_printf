/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macholle <macholle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:31:35 by macholle          #+#    #+#             */
/*   Updated: 2025/10/24 15:31:39 by macholle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_charsrch(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			break ;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

int	ft_type_check(const char *input, va_list args)
{
	char	c;

	if (*input == 's')
		return (ft_printf_str(va_arg(args, char *)));
	if (*input == 'p')
		return (ft_printf_ptr(va_arg(args, void *)));
	if (*input == 'd')
		return (ft_printf_nbrs(48, 10, va_arg(args, int)));
	if (*input == 'i')
		return (ft_printf_nbrs(87, 10, va_arg(args, int)));
	if (*input == 'u')
		return (ft_printf_nbrs(48, 10, va_arg(args, unsigned int)));
	if (*input == 'x')
		return (ft_printf_nbrs(87, 16, va_arg(args, unsigned int)));
	if (*input == 'X')
		return (ft_printf_nbrs(55, 16, va_arg(args, unsigned int)));
	c = va_arg(args, int);
	return (write(1, &c, 1));
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, input);
	while (*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			if (ft_charsrch("cspdiuxX", *input))
				i += ft_type_check(input, args);
			else if (*input == '%')
				i += write (1, "%", 1);
		}
		else
			i += write(1, input, 1);
		input++;
	}
	va_end(args);
	return (i);
}
