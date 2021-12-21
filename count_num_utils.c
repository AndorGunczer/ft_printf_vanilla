/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_num_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:04:35 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/20 10:19:48 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	num_count_hex(unsigned int n)
{
	int			i;
	long long	num;

	if (n == 0)
		return (1);
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

int	num_count_long(long n)
{
	int			i;
	long long	num;

	if (n == 0)
		return (1);
	i = 0;
	num = n;
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	num_count_ptr(unsigned long n)
{
	int			i;
	long long	num;

	if (n == 0x8000000000000000)
		return (16);
	if (n == 0xffffffffffffffff)
		return (16);
	if (n == 0)
		return (1);
	i = 0;
	num = n;
	while (num > 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}
