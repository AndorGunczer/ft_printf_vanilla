/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:48:14 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/10 13:53:17 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	num_count(unsigned long n);
static char	*assigner(unsigned long n, int i, int j, char *str);

char	*ft_itoa_ptr(unsigned long n)
{
	int		i;
	int		digits;
	int		j;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	digits = num_count(n);
	i = digits - 1;
	j = 0;
	str = malloc(sizeof(char) * (digits + 1));
	if (str == 0)
		return (0);
	return (assigner(n, i, j, str));
}

static	int	num_count(unsigned long n)
{
	int			i;
	long long	num;

	i = 0;
	num = n;
	while (num > 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

static char	*assigner(unsigned long n, int i, int j, char *str)
{	
	int	digits;

	digits = num_count(n);
	while (i >= j)
	{
		str[i] = (n % 16) + '0';
		n /= 16;
		i--;
	}
	str[digits] = '\0';
	return (str);
}
