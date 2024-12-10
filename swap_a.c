/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:07:05 by ejonsery          #+#    #+#             */
/*   Updated: 2024/12/10 16:07:41 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(char **tab)
{
	char	*tmp;

	if (tab[0] && tab[1])
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tmp;
		ft_printf("sa\n");
	}
}

void	pa(char	**atab, char	**btab)
{
	int		i;
	int		blen;

	i = ft_tablen(atab);
	if (btab[0])
	{
		while (i > 0)
		{
			atab[i] = atab[i - 1];
			i--;
		}
		atab[0] = btab[0];
		blen = ft_tablen(btab);
		i = 0;
		while (i < blen)
		{
			btab[i] = btab[i + 1];
			i++;
		}
		ft_printf("pa\n");
	}
}

void	ra(char **tab)
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
	ft_printf("ra\n");
}

void	rra(char	**tab)
{
	char	*tmp;
	int		i;

	i = ft_tablen(tab) - 1;
	tmp = tab[i];
	while (i > 0)
	{
		tab[i] = tab[i - 1];
		i--;
	}
	tab[0] = tmp;
	ft_printf("rra\n");
}
