/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:14:43 by ejonsery          #+#    #+#             */
/*   Updated: 2024/10/22 15:16:32 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;
	int	is_negative;

	len = 0;
	is_negative = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		is_negative = 1;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len + 1 + is_negative);
}

static char	*convert_nb(int n, char *res, int i)
{
	int		lim;

	lim = 0;
	res[i] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
		lim = 1;
	}
	if (n == -2147483648)
	{
		res[i - 1] = '8';
		n = (n / 10) * -1;
		i--;
	}
	while (--i >= lim)
	{
		res[i] = (n % 10) + 48;
		n = n / 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*res;

	i = ft_intlen(n);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res = convert_nb(n, res, i);
	return (res);
}
