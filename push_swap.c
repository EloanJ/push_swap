/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:48:38 by ejonsery          #+#    #+#             */
/*   Updated: 2024/12/17 15:24:58 by ejonsery         ###   ########.fr       */
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
		if (!(argv[i]))
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
	(void)ac;
	res = ft_calloc(sizeof(char *), ft_tablen(av) + 1);
	while (av[i])
	{
		res[j] = ft_strdup(av[i]);
		j++;
		i++;
	}
	return (res);
}

int	main(int ac, char **av)
{
	char	**taba;
	char	**tabb;

	if (check_input(ac, av) == 0 || ac == 1)
		return (aff_error(ac));
	if (ac == 2)
		taba = ft_split(av[1], ' ');
	else
		taba = av_dup(av, ac);
	if (!taba)
		return (0);
	is_sort(taba);
	tabb = ft_calloc(sizeof(char *), ft_tablen(taba));
	if (!tabb)
		return (free_tabs(taba, NULL), 0);
	if (ft_tablen(taba) == 5)
		sort_five(taba, tabb);
	push_groups(taba, tabb, ac);
	while (tabb[0])
		push_back(taba, tabb);
	right_order(taba);
	free_tabs(taba, tabb);
}
