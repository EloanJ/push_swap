/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:37:42 by ejonsery          #+#    #+#             */
/*   Updated: 2024/12/06 15:03:20 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_for_small_or_big(char **taba, char **tabb)
{
	if (preswap2(taba) == 1)
		while (the_smallest(taba[0], taba) != 1)
			ra(taba);
	else if (preswap2(taba) == 0)
		while (the_smallest(taba[0], taba) != 1)
			rra(taba);
	pa(taba, tabb);
	if (the_biggest(tabb[0], taba))
		ra(taba);
}

void	push_back(char **taba, char **tabb)
{
	while (tabb[0])
	{
		if (the_biggest(tabb[0], taba))
			swap_for_small_or_big(taba, tabb);
		else if (the_smallest(tabb[0], taba))
			swap_for_small_or_big(taba, tabb);
		else
		{
			if (best_moove(taba, tabb) == 1)
			{
				while (!(ft_atoi(tabb[0]) < ft_atoi(taba[0])
						&& ft_atoi(tabb[0])
						> ft_atoi(taba[ft_tablen(taba) - 1])))
					ra(taba);
			}
			else if (best_moove(taba, tabb) == 2)
			{
				while (!(ft_atoi(tabb[0]) < ft_atoi(taba[0])
						&& ft_atoi(tabb[0])
						> ft_atoi(taba[ft_tablen(taba) - 1])))
					rra(taba);
			}
			pa(taba, tabb);
		}
	}
}

void	free_tabs(char **taba, char **tabb)
{
	int	i;

	i = 0;
	while (taba[i])
	{
		free(taba[i]);
		i++;
	}
	i = 0;
	while (tabb[i])
	{
		free(tabb[i]);
		i++;
	}
	free(taba);
	free(tabb);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	aff_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}
