/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:45:56 by ejonsery          #+#    #+#             */
/*   Updated: 2024/12/10 15:13:46 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(char **atab, char **btab)
{
	sa(atab);
	sb(btab);
}

void	rr(char **atab, char **btab)
{
	ra(atab);
	rb(btab);
}

void	rrr(char **atab, char **btab)
{
	rra(atab);
	rrb(btab);
}

int	power_of_two(int nb)
{
	int	i;
	int	res;
	int	two;

	res = 2;
	i = 0;
	two = 2;
	while (res <= nb)
	{
		res = res * 2;
		i++;
	}
	return (i);
}
