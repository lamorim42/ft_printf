/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:15:09 by lamorim           #+#    #+#             */
/*   Updated: 2021/09/30 20:44:04 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digit(long int c)
{
	int	len;

	if (!c)
		return (1);
	len = 0;
	while (c > 0)
	{
		c /= 10;
		len++;
	}
	return (len);
}

static void	string_filler(char **ptr, long int n_cpy, int signal)
{
	if (!n_cpy)
		*(--*ptr) = '0';
	while (n_cpy)
	{
		*(--*ptr) = n_cpy % 10 + '0';
		n_cpy /= 10;
	}
	if (signal)
		*(--*ptr) = '-';
}

int	ft_putnbr(int number)
{
	long int	n_cpy;
	char		*ptr;
	char		*str;
	int			len;
	int			signal;

	n_cpy = number;
	signal = number < 0;
	if (signal)
		n_cpy = -n_cpy;
	len = ft_count_digit(n_cpy);
	str = (char *)malloc(len + 1 + signal);
	if (!str)
		return ('\0');
	ptr = &str[len + signal];
	*ptr = '\0';
	string_filler(&ptr, n_cpy, signal);
	write(STDOUT, str, len + signal);
	free(str);
	return (len + signal);
}

int	ft_putunbr(unsigned int number)
{
	unsigned int	n_cpy;
	char		*ptr;
	char		*str;
	int			len;

	n_cpy = number;
	len = ft_count_digit(n_cpy);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	ptr = &str[len];
	*ptr = '\0';
	string_filler(&ptr, n_cpy, 0);
	write(STDOUT, str, len);
	free(str);
	return (len);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		write (STDOUT, "(null)", 6);
		return (6);
	}
	while (s[len])
		len++;
	write (STDOUT, s, len);
	return(len);
}
