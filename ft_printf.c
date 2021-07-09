/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:08:55 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/09 09:12:47 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include "libft/libft.h"

static int  ft_isformat(char *str)
{
    if (*str == 'd' || *str == 'i' || *str == 'c' || *str == 's' || *str == 'u'
    || *str == 'p' || *str == 'x' || *str == 'X')
        return (1);
    else
        return (0);
}

int ft_printf(const char *str, ...)
{
    va_list ap;
    void *arg;
    int printcount;

    va_start(ap, str);
    printcount = 0;
    while (*str != '\0')
    {
        if (*str == '%')
        {
            arg = va_arg(ap, void*);
            ft_handletype((char *)str, arg);
            printcount += ft_widthcounter((char *)str, arg);
            while (ft_isformat((char *)str) != 1)
                str++;
        }
        else
        {
            ft_putchar_fd(*str, 1);
            printcount++;
        }
        str++;
    }
    return (printcount);
}