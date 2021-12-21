/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:08:55 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/20 09:37:58 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

static int	ft_isformat(char *str)
{
	if (*str == 'd' || *str == 'i' || *str == 'c' || *str == 's' || *str == 'u'
		|| *str == 'p' || *str == 'x' || *str == 'X')
		return (1);
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		printcount;

	va_start(ap, str);
	printcount = 0;
	while (*str != '\0')
	{
		if (*str == '%' && *(str + 1) == '%')
		{
			printcount += handlepercent((char *)str);
			str++;
		}
		else if (*str == '%')
		{
			printcount += ft_handletype((char *)str, va_arg(ap, void *));
			while (ft_isformat((char *)str) != 1)
				str++;
		}
		else
			ft_putchar_inc(*str, &printcount);
		str++;
	}
	va_end(ap);
	return (printcount);
}
