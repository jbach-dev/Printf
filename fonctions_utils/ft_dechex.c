/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dechex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:18:39 by jbach             #+#    #+#             */
/*   Updated: 2021/12/21 14:18:40 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dec(int c)
{
	int		nb_len;
	long	number;

	number = (long) c;
	nb_len = count_numbers(number);
	if (number < 0)
	{
		ft_putchar_fd('-');
		number = -number;
		nb_len++;
	}
	if (nb_len > 0)
		ft_putnbr_fd(number);
	if (number == 2147483648)
		nb_len = 11;
	return (nb_len);
}

int	ft_u(long c)
{
	int	nb_len;

	nb_len = count_numbers(c);
	if (c < 0)
	{
		c = 4294967296 + c;
		ft_putnbr_fd(c);
		return (10);
	}
	if (nb_len >= 0)
		ft_putnbr_fd(c);
	return (nb_len);
}

void	ft_putnbrbase16(unsigned long int nb, char *base)
{
	unsigned int	size_base;

	size_base = ft_strlen(base);
	if (nb >= size_base)
	{
		ft_putnbrbase16(nb / size_base, base);
		ft_putnbrbase16(nb % size_base, base);
	}
	else if (nb < size_base)
	{
		if (nb > 9)
			ft_putchar_fd(base[nb]);
		else if (nb <= 9)
			ft_putchar_fd((nb + '0'));
	}
}

int	ft_lenbase16(unsigned long int nb, const char f)
{
	int	len;

	len = 0;
	if (f == 'p' && nb == 0)
		len += 1;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	if (f == 'p')
		len += 2;
	return (len);
}

int	ft_hex(unsigned long int c, const char f)
{
	char	*base_small;
	char	*base_upper;

	base_small = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	if (c == 0 && (f == 'x' || f == 'X'))
		return (write(1, "0", 1));
	else if (f == 'x')
		ft_putnbrbase16(c, base_small);
	else if (f == 'X')
		ft_putnbrbase16(c, base_upper);
	else if (f == 'p')
	{
		ft_putstr_fd("0x");
		ft_putnbrbase16(c, base_small);
	}
	return (ft_lenbase16(c, f));
}
