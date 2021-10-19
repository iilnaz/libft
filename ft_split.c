/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwood <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:20:28 by rwood             #+#    #+#             */
/*   Updated: 2021/10/19 17:11:26 by rwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_of_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			i++;
		if (s[i - 1] != c)
			count++;
	}
	return (count);
}

static char	*get_word(char const *s, size_t i, char c)
{
	char	*word;
	size_t	j;
	size_t	len;
	size_t	ind;
	size_t	k;

	k = 0;
	j = 0;
	while (k <= i)
	{
		len = 0;
		while (s[j] == c)
			j++;
		ind = j;
		while (s[j] != c && s[j] != '\0')
		{
			len++;
			j++;
		}
		if (k == i)
			word = ft_substr(s, (unsigned int)ind, len);
		k++;
	}
	return (word);
}

void	*free_split(char **split, size_t count)
{
	size_t	ind;

	ind = 0;
	while (ind < count)
	{
		free(split[ind]);
		ind++;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*word;
	size_t	i;
	size_t	cwords;

	if (!s)
		return (NULL);
	i = 0;
	cwords = count_of_words(s, c);
	res = (char **)malloc((cwords + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res[cwords] = NULL;
	while (i < cwords)
	{
		word = get_word(s, i, c);
		if (!word)
		{
			free(word);
			return (free_split(res, i));
		}
		res[i] = word;
		i++;
	}
	return (res);
}
