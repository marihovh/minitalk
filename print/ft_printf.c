/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:56:23 by marihovh          #+#    #+#             */
/*   Updated: 2023/02/26 21:45:45 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	funkcia(char n, va_list ap)
{
	int					count;
	unsigned long long	nb;

	count = 0;
	if (n == 'c')
		count = ft_putchar(va_arg(ap, int));
	else if (n == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if (n == 'p')
	{
		nb = (unsigned long long)(va_arg(ap, void *));
		write (1, "0x", 2);
		count = ft_putpoint(nb);
	}
	else if (n == 'd' || n == 'i')
		count = ft_putnbr(va_arg(ap, long long));
	else if (n == 'u')
		count = ft_putunbr(va_arg(ap, unsigned long long));
	else if (n == 'x')
		count = ft_puthexl(va_arg(ap, unsigned int));
	else if (n == 'X')
		count = ft_puthexu(va_arg(ap, unsigned int));
	else
		count = write (1, &n, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			len += funkcia(str[++i], ap);
		else if (str[i])
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
