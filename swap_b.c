/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:41:51 by ejonsery          #+#    #+#             */
/*   Updated: 2024/12/06 12:07:37 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(char **tab)
{
	char	*tmp;

	if (tab[0] && tab[1])
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tmp;
		ft_printf("sb\n");
	}
}

void	pb(char	**atab, char	**btab)
{
	int		i;
	int		alen;

	i = ft_tablen(btab);
	if (atab[0])
	{
		while (i > 0)
		{
			btab[i] = btab[i - 1];
			i--;
		}
		btab[0] = atab[0];
		alen = ft_tablen(atab);
		i = 0;
		while (i < alen)
		{
			atab[i] = atab[i + 1];
			i++;
		}
		ft_printf("pb\n");
	}
}

void	rb(char **tab)
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
	ft_printf("rb\n");
}

void	rrb(char	**tab)
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
	ft_printf("rrb\n");
}
