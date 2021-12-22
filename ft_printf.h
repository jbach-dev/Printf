/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:22:42 by jbach             #+#    #+#             */
/*   Updated: 2021/12/15 18:22:43 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_printf(const char *f, ...);
int		ft_carac(va_list args, const char f);

size_t	ft_strlen(const char *s);
int		ft_putstr_fd(const char *f);
int		ft_putchar_fd(int c);
char	count_numbers(int nb);
void	ft_putnbr_fd(long nb);

int		ft_dec(int c);
int		ft_u(long c);
void	ft_putnbrbase16(unsigned long int nb, char *base);
int		ft_lenbase16(unsigned long int nb, const char f);
int		ft_hex(unsigned long int c, const char f);

#endif