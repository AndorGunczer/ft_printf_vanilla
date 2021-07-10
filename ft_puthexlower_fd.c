/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlower_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:50:06 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/09 15:08:38 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	ft_converthex(unsigned int hex);

void	ft_puthexlower_fd(unsigned int n, int fd)
{
	if (n == 0x80000000)
		ft_putstr_fd("80000000", fd);
	else if (n >= 16)
	{
		ft_puthexlower_fd(n / 16, fd);
		ft_putchar_fd(ft_converthex(n % 16), fd);
	}
	else
		ft_putchar_fd(ft_converthex(n), fd);
}

static char	ft_converthex(unsigned int hex)
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
