/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:00:07 by ejonsery          #+#    #+#             */
/*   Updated: 2024/12/18 12:47:43 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	right_order(char **taba)
{
	if (preswap2(taba) == 1)
		while (the_smallest(taba[0], taba) != 1)
			ra(taba);
	else if (preswap2(taba) == 0)
		while (the_smallest(taba[0], taba) != 1)
			rra(taba);
}

void	small_sort(char **taba)
{
	if (ft_atoi(taba[0]) < ft_atoi(taba[1])
		&& ft_atoi(taba[1]) > ft_atoi(taba[2]))
		rra(taba);
	if (ft_atoi(taba[0]) > ft_atoi(taba[1])
		&& ft_atoi(taba[1]) > ft_atoi(taba[2]))
		rra(taba);
	if (ft_atoi(taba[0]) < ft_atoi(taba[1])
		&& ft_atoi(taba[1]) > ft_atoi(taba[2]))
		rra(taba);
	if (ft_atoi(taba[0]) > ft_atoi(taba[1])
		&& ft_atoi(taba[1]) < ft_atoi(taba[2])
		&& ft_atoi(taba[0]) > ft_atoi(taba[2]))
		ra(taba);
	if (ft_atoi(taba[0]) > ft_atoi(taba[1])
		&& ft_atoi(taba[1]) < ft_atoi(taba[2]))
		sa(taba);
}

void	sort_five(char **taba, char **tabb)
{

	while (ft_tablen(taba) != 3)
		pb(taba, tabb);
	small_sort(taba);
	push_back(taba, tabb);
	right_order(taba);
	free_tabs(taba, tabb);
	exit (1);
}

int	ft_find_min(char **tab)
{
	char	*min;
	int		i;

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

int	ft_find_end(char **t_a, int distance)
{
	int		min;
	int		i;
	int		j;
	int		*tab;

	j = 0;
	tab = ft_calloc(sizeof(int), distance + 1);
	tab[0] = ft_find_min(t_a);
	while (distance--)
	{
		i = 0;
		min = __INT_MAX__;
		while (t_a[i])
		{
			if ((ft_atoi(t_a[i]) != tab[j]) && (ft_atoi(t_a[i]) > tab[j])
				&& (ft_atoi(t_a[i]) < min))
				min = ft_atoi(t_a[i]);
			i++;
		}
		tab[++j] = min;
	}
	min = tab[j];
	return (free(tab), min);
}
