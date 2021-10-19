/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwood <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:52:00 by rwood             #+#    #+#             */
/*   Updated: 2021/10/17 19:50:55 by rwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(int n)
{
	size_t		len;
	long int	divisor;

	len = 0;
	divisor = 1;
	while (n / divisor != 0)
	{
		divisor *= 10;
		len++;
	}
	if (n == 0)
		return (1);
	return (len);
}

static int	take_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		is_neg;
	size_t	len;

	is_neg = n < 0;
	len = num_len(n);
	str = (char *)malloc((len + is_neg + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len + is_neg] = 0;
	if (n == 0)
		str[0] = '0';
	if (is_neg)
		str[0] = '-';
	while (len)
	{
		str[len + is_neg - 1] = take_abs(n % 10) + '0';
		len--;
		n /= 10;
	}
	return (str);
}
