/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:00:07 by ejonsery          #+#    #+#             */
/*   Updated: 2024/12/17 15:02:55 by ejonsery         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (ft_tablen(taba) != 3)
		pb(taba,tabb);
	small_sort(taba);
	push_back(taba, tabb);
	right_order(taba);
	free_tabs(taba, tabb);
	exit (1);
}