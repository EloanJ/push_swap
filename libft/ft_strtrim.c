/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:35:44 by ejonsery          #+#    #+#             */
/*   Updated: 2024/10/22 15:29:11 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count_set(char const *s1, char const *set)
{
	int		i;
	size_t	t;
	int		in_words;

	i = -1;
	t = 0;
	in_words = 0;
	while (s1[++i])
	{
		if (is_set(s1[i], set) && !in_words)
			t++;
		if (!is_set(s1[i], set))
			in_words = 1;
	}
	in_words = 0;
	while (--i >= 0)
	{
		if (is_set(s1[i], set) && !in_words)
			t++;
		if (!is_set(s1[i], set))
			in_words = 1;
	}
	if (t >= ft_strlen(s1))
		return (ft_strlen(s1));
	return (t);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*res;
	int		stop;

	i = 0;
	stop = ft_strlen(s1) - 1;
	j = -1;
	res = malloc(sizeof(char) * (ft_strlen(s1) - count_set(s1, set)) + 1);
	if (!res)
		return (NULL);
	while (is_set(s1[i], set) && s1[i])
		i++;
	while (is_set(s1[stop], set) && s1[stop])
		stop--;
	while (i <= stop)
	{
		res[++j] = s1[i];
		i++;
	}
	res[j + 1] = '\0';
	return (res);
}
