/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widthcounter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:40:11 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/10 09:22:11 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_widthcounter(char *str, void *arg)
{
	char	type;
	int		width;

	type = ft_detertype(str);
	if (type == 's')
		width = ft_strlen((char *)arg);
	if (type == 'c')
		width = 1;
	if (type == 'd' || type == 'i')
		width = ft_strlen(ft_itoa((int)arg));
	if (type == 'p')
		width = 2 + ft_strlen(ft_itoa_ptr((unsigned long)arg));
	if (type == 'u')
		width = ft_strlen(ft_itoa_long((unsigned int)arg));
	if (type == 'x')
		width = ft_strlen(ft_itoa_hex((unsigned int)arg));
	if (type == 'X')
		width = ft_strlen(ft_itoa_hex((unsigned int)arg));
	return (width);
}
