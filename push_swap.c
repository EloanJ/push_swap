/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:48:38 by ejonsery          #+#    #+#             */
/*   Updated: 2024/12/18 13:26:43 by ejonsery         ###   ########.fr       */
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

int	check_input(int len, char **taba)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (!(taba[i]))
			return (0);
		if (!ft_isnumber(taba[i]))
			return (0);
		if (ft_atol(taba[i]) > 2147483647 || ft_atol(taba[i]) < -2147483648
			|| ft_strlen(taba[i]) > 11)
			return (0);
		while (j < len)
		{
			if (ft_atol(taba[i]) == ft_atol(taba[j]) && j != i)
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
	if (!res)
		return (0);
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

	if (ac == 1)
		return (aff_error(0));
	if (ac == 2)
		taba = ft_split(av[1], ' ');
	else
		taba = av_dup(av, ac);
	if (!taba)
		return (0);
	if (check_input(ft_tablen(taba), taba) == 0)
		return (free_tabs(taba, NULL), aff_error(2));
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
