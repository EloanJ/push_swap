/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quiet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:33:47 by ejonsery          #+#    #+#             */
/*   Updated: 2024/12/06 11:53:41 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quiet_ra(char **tab)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = tab[0];
	while (i < ft_tablen(tab))
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i - 1] = tmp;
}

void	quiet_rra(char	**tab)
{
	char	*tmp;
	int		i;

	i = ft_tablen(tab);
	tmp = tab[i - 1];
	while (i > 0)
	{
		tab[i] = tab[i - 1];
		i--;
	}
	tab[0] = tmp;
	tab[ft_tablen(tab) - 1] = NULL;
}

void	quiet_rb(char **tab)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = tab[0];
	while (i < ft_tablen(tab))
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i - 1] = tmp;
}

void	quiet_rrb(char	**tab)
{
	char	*tmp;
	int		i;

	i = ft_tablen(tab);
	tmp = tab[i - 1];
	while (i > 0)
	{
		tab[i] = tab[i - 1];
		i--;
	}
	tab[0] = tmp;
	tab[ft_tablen(tab) - 1] = NULL;
}
