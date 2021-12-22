/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:17:15 by jbach             #+#    #+#             */
/*   Updated: 2021/12/21 14:17:16 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr_fd(const char *f)
{
	int	i;

	i = 0;
	if (!f)
	{
		ft_putstr_fd("(null)");
		i = 6;
		return (i);
	}
	while (f[i])
	{
		write(1, &f[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar_fd(int c)
{
	write (1, &c, 1);
	return (1);
}

char	count_numbers(int nb)
{
	size_t	i;

	i = 0;
	if (nb < 0)
		nb = -nb;
	while (nb >= 10)
	{
		i++;
		nb = nb / 10;
	}
	i++;
	return (i);
}

void	ft_putnbr_fd(long nb)
{
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10);
		ft_putnbr_fd(nb % 10);
	}
	if (nb <= 9)
		ft_putchar_fd(nb + 48);
}
