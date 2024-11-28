/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:08:22 by ejonsery          #+#    #+#             */
/*   Updated: 2024/11/28 16:30:30 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int the_biggest(char *nbr, char **tabb)
{
	int	i;

	i = 0;
	while (tabb[i])
	{
		if (ft_atoi(nbr) < ft_atoi(tabb[i]))
			return (0);
		i++;
	}
	return (1);
}

int the_smallest(char *nbr, char **tabb)
{
	int	i;

	i = 0;
	while (tabb[i])
	{
		if (ft_atoi(nbr) > ft_atoi(tabb[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**tab_dup(char **tab, int len)
{
	int		i;
	char	**res;

	i = 0;
	res = ft_calloc(sizeof(char *), len + 1);
	while (tab[i])
	{
		res[i] = ft_strdup(tab[i]);
		i++;
	}
	return (res);
}

int	preswap(char **tab, char *value)
{
	int	i;
	int	j;
	char **clone;
	char **clone2;

	clone = tab_dup(tab, ft_tablen(tab) + 1);
	if (!clone)
		return(-1);
	i = 0;
	j = 0;
	while (!(ft_atoi(value) < ft_atoi(clone[0])
		&& ft_atoi(value) > ft_atoi(clone[ft_tablen(clone) - 1])))
	{
		quiet_ra(clone);
		i++;
	}
	clone2 = tab_dup(tab, ft_tablen(tab) + 1);
	if (!clone2)
		return(-1);
	while (!(ft_atoi(value) < ft_atoi(clone2[0])
		&& ft_atoi(value) > ft_atoi(clone2[ft_tablen(clone2) - 1])))
	{
		quiet_rra(clone2);
		j++;
	}
	if (i < j)
		return (1);
	return (0);
}

int	preswap2(char **tab)
{
	int		i;
	int		j;
	char	**clone;
	char	**clone2;
	
	clone = tab_dup(tab, ft_tablen(tab) + 1);
	clone2 = tab_dup(tab, ft_tablen(tab) + 1);
	if (!clone || !clone2)
		return(-1);
	i = 0;
	j = 0;
	while (the_smallest(clone[0], clone) != 1)
	{
		quiet_ra(clone);
		i++;
	}
	while (the_smallest(clone2[0], clone2) != 1)
	{
		quiet_rra(clone2);
		j++;
	}
	if (i < j)
		return (1);
	return (0);
}
