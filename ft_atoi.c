/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwood <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:14:31 by rwood             #+#    #+#             */
/*   Updated: 2021/10/18 19:28:38 by rwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	ind;
	int	sign;
	int	res;

	ind = 0;
	sign = 1;
	res = 0;
	while (str[ind] == ' ' || str[ind] == '\t' || str[ind] == '\n'
		|| str[ind] == '\v' || str[ind] == '\r' || str[ind] == '\f')
		ind++;
	if (str[ind] == '+' || str[ind] == '-')
		sign *= 44 - str[ind++];
	while (str[ind] >= '0' && str[ind] <= '9')
	{
		if (res > 2147483647 / 10 || (res == 2147483647 / 10
				&& str[ind] - '0' >= 9))
			return ((-sign - 1) / 2);
		if (res == 2147483647 / 10
			&& (str[ind] - '0' == 7 || str[ind] - '0' == 8))
			return (sign * 2147483647 + ((sign - 1) / 2));
		res = res * 10 + str[ind] - '0';
		ind++;
	}
	return (res * sign);
}
