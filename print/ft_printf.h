/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:54:07 by marihovh          #+#    #+#             */
/*   Updated: 2023/02/23 16:56:00 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_strlen(char *str);
int	ft_putchar(char n);
int	ft_putstr(char *s);
int	ft_printf(const char *str, ...);
int	funkcia(char n, va_list ap);
int	ft_putpoint(unsigned long long nb);
int	ft_printf(const char *str, ...);
int	ft_putnbr(int nb);
int	ft_putunbr(unsigned int nb);
int	ft_puthexl(unsigned int nb);
int	ft_puthexu(unsigned int nb);
#endif
