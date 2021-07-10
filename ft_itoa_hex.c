/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:04:35 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/10 09:01:52 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	num_count(unsigned int n);
static char	*assigner(unsigned int n, int i, int j, char *str);
static char	ft_converthex(unsigned int hex);

char	*ft_itoa_hex(unsigned int n)
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

static	int	num_count(unsigned int n)
{
	int			i;
	long long	num;

	i = 0;
	num = n;
	if (n == 0x80000000)
		return (8);
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

static char	*assigner(unsigned int n, int i, int j, char *str)
{	
	int	digits;

	digits = num_count(n);
	if (n == 0x80000000)
	{
		ft_strlcpy(str, "80000000", 9);
		return (str);
	}
	while (i >= j)
	{
		if (n % 16 < 10)
			str[i] = ft_converthex(n % 16);
		else
			str[i] = (n % 16) + '0';
		n /= 16;
		i--;
	}
	str[digits] = '\0';
	return (str);
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
