/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handletype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:30:54 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/02 11:25:45 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include "libft/libft.h"

static int  ft_isformat(char *str);

void    ft_handletype(char *str, void *arg)
{
    while (ft_isformat(str) != 1)
        str++;
    if (*str == 'c')
        ft_putchar_fd((char)arg, 1);
    else if (*str == 's')
        ft_putstr_fd((char *)arg, 1);
    else if (*str == 'p')
        ft_puthexpointer_fd((long)arg, 1);
    else if (*str == 'd' || *str == 'i')
        ft_putnbr_fd((int)arg, 1);
    else if (*str == 'x')
        ft_puthexlower_fd((unsigned int)arg, 1);
    else if (*str == 'X')
        ft_puthexupper_fd((unsigned int)arg, 1);
    else if (*str == 'u')
        ft_putunsnbr_fd((unsigned int)arg, 1);
}

static int  ft_isformat(char *str)
{
    if (*str == 'd' || *str == 'i' || *str == 'c' || *str == 's' || *str == 'u'
    || *str == 'p' || *str == 'x' || *str == 'X')
        return (1);
    else
        return (0);
}