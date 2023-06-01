/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:10:33 by marihovh          #+#    #+#             */
/*   Updated: 2023/02/23 17:14:33 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 10)
		i = ft_putnbr (nb / 10);
	i++;
	ft_putchar((nb % 10) + '0');
	return (i);
}

int	ft_puthexl(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 15)
		i = ft_puthexl(nb / 16);
	i++;
	ft_putchar("0123456789abcdef"[nb % 16]);
	return (i);
}

int	ft_puthexu(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 15)
		i = ft_puthexu(nb / 16);
	i++;
	ft_putchar("0123456789ABCDEF"[nb % 16]);
	return (i);
}
