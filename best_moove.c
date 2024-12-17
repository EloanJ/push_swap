/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_moove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:01:14 by ejonsery          #+#    #+#             */
/*   Updated: 2024/12/17 17:07:39 by ejonsery         ###   ########.fr       */
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
	free_tabs(clone, NULL);
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
	free_tabs(clone2, NULL);
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
int    ft_find_min(char **tab)
{
    char    *min;
    int        i;

    i = 0;
    min = tab[0];
    while (tab[i])
    {
        if (ft_atoi(tab[i]) < ft_atoi(min))
            min = tab[i];
        i++;
    }
    return (ft_atoi(min));
}

int    ft_find_end(char **t_a, int distance)
{
	int    min;
	int    i;
	int    j = 0;
	int    *tab;

	tab = ft_calloc(sizeof(int), distance + 1);
	tab[0] = ft_find_min(t_a);
	while (distance--)
	{
		i = 0;
		min = __INT_MAX__;
		while (t_a[i])
		{
			if ((ft_atoi(t_a[i]) != tab[j]) && (ft_atoi(t_a[i]) > tab[j]) && (ft_atoi(t_a[i]) < min))
				min = ft_atoi(t_a[i]);
			i++;
		}
		tab[++j] = min;
	}
	min = tab[j];
	return (free(tab), min);
}

void	do_push(char **taba, char **tabb, int j, int group_len)
{
	int	r;
	int	min;
	int other_end;

	r = 0;
	j = ft_find_end(taba, group_len);
	min = ft_find_min(taba);
	other_end = ft_find_end(taba, group_len * 2);
	while (r < ft_tablen(taba) && taba[0])
	{
		if (ft_atoi(taba[0]) >= min && ft_atoi(taba[0]) < j)
			pb(taba, tabb);
		else if (ft_atoi(taba[0]) >= j && ft_atoi(taba[0]) < other_end)
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

	(void)ac;
	group_len = (ft_tablen(taba) - 3) / (power_of_two(ft_tablen(taba)));
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
