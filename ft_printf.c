/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:07:14 by lamorim           #+#    #+#             */
/*   Updated: 2021/09/30 21:30:23 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_ph(const char **fmt, va_list ap, int *printrd_chars);

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		printrd_chars;

	printrd_chars = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			ft_put_ph(&fmt, ap, &printrd_chars);
			fmt++;
		}
		ft_putchar(*fmt);
		printrd_chars++;
		if(*fmt)
			fmt++;
	}
	va_end(ap);
	return (printrd_chars);
}

static int	ft_put_ph(const char **fmt, va_list ap, int *printrd_chars)
{
	if (**fmt == 'c')
		*printrd_chars += ft_putchar(va_arg(ap, int));
	else if (**fmt == 's')
		*printrd_chars += ft_putstr(va_arg(ap, char *));
	else if (**fmt == 'p')
		*printrd_chars += ft_putstr(ft_itoa_address(va_arg(ap, void *)));
	else if (**fmt == 'd' || **fmt == 'i')
		*printrd_chars += ft_putnbr(va_arg(ap, int));
	else if (**fmt == 'u')
		*printrd_chars += ft_putunbr(va_arg(ap, unsigned int));
	else if (**fmt == 'x')
		*printrd_chars += ft_putstr(ft_itoa_base(va_arg(ap, unsigned int),\
				   	HEX_BASE, LOWER));
	else if (**fmt == 'X')
		*printrd_chars += ft_putstr(ft_itoa_base(va_arg(ap, unsigned int),\
				   	HEX_BASE, UPPER));
	else if (**fmt == '%')
		*printrd_chars += ft_putchar('%');
	return (*printrd_chars);
}
