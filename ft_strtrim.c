/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwood <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:38:14 by rwood             #+#    #+#             */
/*   Updated: 2021/10/19 17:13:41 by rwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_char_in_set(char ch, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (ch == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*res;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && is_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && is_char_in_set(s1[end], set))
		end--;
	res = (char *)malloc((end - start + 2) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (start <= end && ft_strlen(s1))
	{
		res[i] = s1[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
