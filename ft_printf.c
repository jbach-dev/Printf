/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:28:24 by jbach             #+#    #+#             */
/*   Updated: 2021/12/15 18:17:04 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_carac(va_list args, const char f)
{
	int	len;

	len = 0;
	if (f == 'c')
		len += ft_putchar_fd(va_arg(args, int));
	else if (f == 's')
		len += ft_putstr_fd(va_arg(args, char *));
	else if (f == 'i' || f == 'd')
		len += ft_dec(va_arg(args, int));
	else if (f == 'u')
		len += ft_u(va_arg(args, int));
	else if (f == 'x' || f == 'X')
		len += ft_hex(va_arg(args, unsigned int), f);
	else if (f == 'p')
		len += ft_hex(va_arg(args, unsigned long int), f);
	else if (f == '%')
		len += ft_putchar_fd('%');
	return (len);
}

int	ft_printf(const char *f, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, f);
	while (f[i])
	{
		if (f[i] == '%')
		{
			len += ft_carac(args, f[i + 1]);
			i += 2;
		}
		else
		{
			len += ft_putchar_fd(f[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}
