/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uteis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:35:44 by lamorim           #+#    #+#             */
/*   Updated: 2021/09/30 20:39:46 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_address(void *ads)
{
	unsigned long	ads_cpy;
	const char		*prefix;
	char			*temp;
	char			*nbr;

	prefix = "0x";
	ads_cpy = (unsigned long) ads;
	temp = ft_itoa_base(ads_cpy, HEX_BASE, LOWER);
	nbr = ft_strjoin(prefix, temp);
	free(temp);
	return (nbr);
}

int	ft_putchar(char c)
{
	write (STDOUT, &c, 1);
	return(1);
}
