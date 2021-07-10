/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexupper_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:11:04 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/09 15:27:51 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	ft_converthex(unsigned int hex);

void	ft_puthexupper_fd(unsigned int n, int fd)
{
	if (n == 0x80000000)
		ft_putstr_fd("80000000", fd);
	else if (n >= 16)
	{
		ft_puthexupper_fd(n / 16, fd);
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
		return ('A');
	if (hex == 11)
		return ('B');
	if (hex == 12)
		return ('C');
	if (hex == 13)
		return ('D');
	if (hex == 14)
		return ('E');
	if (hex == 15)
		return ('F');
	return (0);
}
