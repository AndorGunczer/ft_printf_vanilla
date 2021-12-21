/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widthcounter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:40:11 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/19 19:18:21 by agunczer         ###   ########.fr       */
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
		width = num_count((int)arg);
	if (type == 'p')
		width = 2 + num_count_ptr((unsigned long)arg);
	if (type == 'u')
		width = num_count_long((unsigned int)arg);
	if (type == 'x')
		width = num_count_hex((unsigned int)arg);
	if (type == 'X')
		width = num_count_hex((unsigned int)arg);
	return (width);
}
