/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:03:00 by marihovh          #+#    #+#             */
/*   Updated: 2023/02/23 20:05:36 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (write (1, "(null)", 6));
	i = -1;
	while (s[++i])
		write (1, &s[i], 1);
	return (ft_strlen(s));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_putpoint(unsigned long long nb)
{
	int	i;

	i = 2;
	if (nb > 15)
		i = ft_putpoint(nb / 16);
	i++;
	ft_putchar("0123456789abcdef"[nb % 16]);
	return (i);
}

int	ft_putnbr(int nb)
{
	int				i;
	unsigned int	nb1;
	int				c;

	i = 0;
	c = 0;
	if (nb < 0)
	{
		c = ft_putchar ('-');
		nb *= -1;
	}
	nb1 = (unsigned int)nb;
	if (nb1 >= 10)
		i = ft_putnbr (nb1 / 10);
	i++;
	ft_putchar(nb1 % 10 + '0');
	return (i + c);
}
