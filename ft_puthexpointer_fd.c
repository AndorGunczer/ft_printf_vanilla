/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexpointer_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:26:00 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/20 11:03:06 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	ft_converthex(unsigned long hex);

void	ft_puthexpointer_fd(unsigned long n, int fd)
{
	if (n >= 16)
	{
		ft_puthexpointer_fd(n / 16, fd);
		ft_putchar_fd(ft_converthex(n % 16), fd);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_putchar_fd(ft_converthex(n), fd);
	}
}

static char	ft_converthex(unsigned long hex)
{
	if (hex >= 0 && hex <= 9)
		return (hex + '0');
	if (hex == 10)
		return ('a');
	if (hex == 11)
		return ('b');
	if (hex == 12)
		return ('c');
	if (hex == 13)
		return ('d');
	if (hex == 14)
		return ('e');
	if (hex == 15)
		return ('f');
	return (0);
}
