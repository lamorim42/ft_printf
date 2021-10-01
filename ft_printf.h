/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:39:47 by lamorim           #+#    #+#             */
/*   Updated: 2021/09/30 21:14:07 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define LOWER 0
# define UPPER 1
# define STDOUT 1
# define HEX_BASE 16

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *fmt, ...);
char	*ft_itoa_address(void *ads);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int number);
int		ft_putunbr(unsigned int number);

#endif
