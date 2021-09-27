/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:07:14 by lamorim           #+#    #+#             */
/*   Updated: 2021/09/26 21:41:39 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_read_string(const char *fmt, va_list ap);
static void	ft_check_fmt(const char *fmt, va_list ap);

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	ft_read_string(fmt, ap);
	va_end(ap);
	return (0);
}

static void	ft_read_string(const char *fmt, va_list ap)
{
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			ft_check_fmt(fmt, ap);
			fmt++;
		}
		ft_putchar_fd(*fmt, 1);
		if (*fmt)
			fmt++;
	}
}

static void	ft_check_fmt(const char *fmt, va_list ap)
{
	if (*fmt == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (*fmt == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
//	else if (*fmt == 'p')
//		put_hex
	else if (*fmt == 'd' || *fmt == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
//	else if (*fmt == 'u')
//		put_long_nbr
//	else if (*fmt == 'x')
//		put_hex
//	else if (*fmt == 'X')
//		put_hex
	else if (*fmt == '%')
		ft_putchar_fd('%', 1);
}
