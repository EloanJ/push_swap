/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:48:38 by ejonsery          #+#    #+#             */
/*   Updated: 2024/12/05 14:53:19 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atol(const char *nptr)
{
	long int	i;
	int			n;
	long int	res;

	i = 0;
	n = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			n *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res * n);
}

int	check_input(int ac, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < ac)
	{
		if (!ft_isnumber(argv[i]))
			return (0);
		if (ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) < -2147483648)
			return (0);
		while (j < ac)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]) && j != i)
				return (0);
			j++;
		}
		i++;
		j = i;
	}
	return (1);
}

char	**av_dup(char **av, int ac)
{
	int		i;
	int		j;
	char	**res;

	i = 1;
	j = 0;
	res = ft_calloc(sizeof(char *), ac);
	while (av[i])
	{
		res[j] = ft_strdup(av[i]);
		j++;
		i++;
	}
	return (res);
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

int	main(int ac, char **av)
{
	char	**taba;
	char	**tabb;
	int		j;
	int		group_len;
	int		r;

	taba = av_dup(av, ac);
	if  (!taba)
		return (0);
	tabb = ft_calloc(sizeof(char *), ac - 1);
	if (!tabb)
		return (0);
	group_len = (ac - 4) / 8;
	if (group_len < 1)
		group_len = 1;
	j = group_len;
	while (ft_tablen(taba) > 3)
	{
		r = 0;
		while (r <ft_tablen(taba) && taba[0])
		{
			
			if (ft_atoi(taba[0]) >= (j - group_len) && ft_atoi(taba[0]) < j)
				pb(taba,tabb);
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
		}
		j += group_len * 2;
		
	}
	if (ft_tablen(taba) == 3)
		small_sort(taba);
	else
	{
		pa(taba, tabb);
		pa(taba, tabb);
		pa(taba, tabb);
		small_sort(taba);
	}	
	while(tabb[0])
	{
		if (the_biggest(tabb[0], taba) == 1)
		{
			if (preswap2(taba) == 1)
				while (the_smallest(taba[0], taba) != 1)
					ra(taba);
			else if (preswap2(taba) == 0)
				while (the_smallest(taba[0], taba) != 1)
					rra(taba);
			pa(taba, tabb);
			ra(taba);
		}
		else if (the_smallest(tabb[0], taba))
		{
			if (preswap2(taba) == 1)
				while (the_smallest(taba[0], taba) != 1)
					ra(taba);
			else if (preswap2(taba) == 0)
				while (the_smallest(taba[0], taba) != 1)
					rra(taba);
			pa(taba, tabb);
		}
		else
		{
	
			if (best_moove(taba, tabb) == 1)
			{
				while (!(ft_atoi(tabb[0]) < ft_atoi(taba[0])
					&& ft_atoi(tabb[0]) > ft_atoi(taba[ft_tablen(taba) - 1])))
					ra(taba);
			}
			else if (best_moove(taba, tabb) == 2)
			{
				while (!(ft_atoi(tabb[0]) < ft_atoi(taba[0])
					&& ft_atoi(tabb[0]) > ft_atoi(taba[ft_tablen(taba) - 1])))
					rra(taba);
			}
			else if (best_moove(taba, tabb) == 3)
			{
				while (!(ft_atoi(tabb[0]) < ft_atoi(taba[0])
					&& ft_atoi(tabb[0]) > ft_atoi(taba[ft_tablen(taba) - 1])))
					rb(tabb);
			}
			else if (best_moove(taba, tabb) == 4)
			{
				while (!(ft_atoi(tabb[0]) < ft_atoi(taba[0])
					&& ft_atoi(tabb[0]) > ft_atoi(taba[ft_tablen(taba) - 1])))
					rrb(tabb);
			}
			pa(taba, tabb);
		} 
	}
	if (preswap2(taba) == 1)
		while (the_smallest(taba[0], taba) != 1)
			ra(taba);
	else if (preswap2(taba) == 0)
		while (the_smallest(taba[0], taba) != 1)
			rra(taba);
}
