/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:25:21 by ejonsery          #+#    #+#             */
/*   Updated: 2024/10/22 17:15:34 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == sep && s[i])
			i++;
		if (s[i])
		{
			count++;
			while (s[i] != sep && s[i])
				i++;
		}
	}
	return (count);
}

static char	*ft_strdup_split(const char *src, int start, int end)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (end - start + 1));
	if (!dest)
		return (NULL);
	while (start < end)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**free_split(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**res;

	i = 0;
	j = 0;
	res = ft_calloc(sizeof(char *), (ft_count_words(s, c) + 1));
	if (!res)
		return (NULL);
	if (!s)
		return (free(res), NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (i > start)
			res[j++] = ft_strdup_split(s, start, i);
		if (!res[j - 1] && j != 0)
			return (free_split(res));
	}
	return (res);
}
