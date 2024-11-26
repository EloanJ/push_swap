/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:08:22 by ejonsery          #+#    #+#             */
/*   Updated: 2024/11/26 15:16:43 by ejonsery         ###   ########.fr       */
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