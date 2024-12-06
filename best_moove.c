/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_moove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:01:14 by ejonsery          #+#    #+#             */
/*   Updated: 2024/12/06 15:48:25 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra_try(char **tab, char *value)
{
	int		i;
	char	**clone;

	clone = tab_dup(tab, ft_tablen(tab) + 1);
	if (!clone)
		return (-1);
	i = 0;
	while (!(ft_atoi(value) < ft_atoi(clone[0])
			&& ft_atoi(value) > ft_atoi(clone[ft_tablen(clone) - 1])))
	{
		quiet_ra(clone);
		i++;
	}
	free_tab(clone);
	return (i);
}

int	rra_try(char **tab, char *value)
{
	char	**clone2;
	int		j;

	clone2 = tab_dup(tab, ft_tablen(tab) + 1);
	if (!clone2)
		return (-1);
	j = 0;
	while (!(ft_atoi(value) < ft_atoi(clone2[0])
			&& ft_atoi(value) > ft_atoi(clone2[ft_tablen(clone2) - 1])))
	{
		quiet_rra(clone2);
		j++;
	}
	free_tab(clone2);
	return (j);
}

int	best_moove(char **taba, char **tabb)
{
	int	nb_ra;
	int	nb_rra;

	nb_ra = ra_try(taba, tabb[0]);
	nb_rra = rra_try(taba, tabb[0]);
	if (nb_ra <= nb_rra)
		return (1);
	else
		return (2);
}

void	do_push(char **taba, char **tabb, int j, int group_len)
{
	int	r;

	r = 0;
	while (r < ft_tablen(taba) && taba[0])
	{
		if (ft_atoi(taba[0]) >= (j - group_len) && ft_atoi(taba[0]) < j)
			pb(taba, tabb);
		else if (ft_atoi(taba[0]) >= j && ft_atoi(taba[0]) < (j + group_len))
		{
			pb(taba, tabb);
			rb(tabb);
		}
		else
		{
			ra(taba);
			r++;
		}
		if (ft_tablen(taba) == 3)
			break ;
	}
}

void	push_groups(char **taba, char **tabb, int ac)
{
	int	group_len;
	int	j;

	group_len = (ac - 4) / 8;
	if (group_len < 1)
		group_len = 1;
	j = group_len;
	while (ft_tablen(taba) > 3)
	{
		do_push(taba, tabb, j, group_len);
		j += group_len * 2;
	}
	small_sort(taba);
}
