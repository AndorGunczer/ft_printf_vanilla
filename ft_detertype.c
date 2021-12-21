/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detertype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:26:13 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/19 18:33:34 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_isformat(char *str);

char	ft_detertype(char *str)
{
	str++;
	while (ft_isformat((char *)str) != 1)
		str++;
	if (*str == 'c')
		return ('c');
	else if (*str == 's')
		return ('s');
	else if (*str == 'p')
		return ('p');
	else if (*str == 'd')
		return ('d');
	else if (*str == 'i')
		return ('i');
	else if (*str == 'x')
		return ('x');
	else if (*str == 'X')
		return ('X');
	else if (*str == 'u')
		return ('u');
	return (0);
}

static int	ft_isformat(char *str)
{
	if (*str == 'd' || *str == 'i' || *str == 'c' || *str == 's' || *str == 'u'
		|| *str == 'p' || *str == 'x' || *str == 'X' || *str == '%')
		return (1);
	else
		return (0);
}
