/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macholle <macholle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:59:35 by macholle          #+#    #+#             */
/*   Updated: 2025/10/30 20:59:59 by macholle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define ULONG_MAX 0xFFFFFFFFUL

int		ft_printf(const char *input, ...);
int		ft_printf_nbrs(int fd, int dvsr, long nb);
int		ft_printf_ptr(void *ptr);
int		ft_printf_str(char *c);

#endif
