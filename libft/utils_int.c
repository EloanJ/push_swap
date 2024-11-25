/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:07:45 by ejonsery          #+#    #+#             */
/*   Updated: 2024/11/25 15:41:05 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putx(unsigned int nbr, char *base)
{
	int		res;
	char	*buff;
	int		i;

	res = 0;
	i = 0;
	if (nbr == 0)
		return (ft_putchar_count('0'));
	buff = malloc(9);
	if (!buff)
		return (-1);
	while (nbr > 0)
	{
		buff[i] = base[nbr % ft_strlen(base)];
		nbr = nbr / ft_strlen(base);
		i++;
	}
	res = i;
	buff[i] = '\0';
	while (--i >= 0)
		if (ft_putchar_count(buff[i]) <= 0)
			return (free(buff), -1);
	free(buff);
	return (res);
}

int	ft_putunsigned_iter(unsigned int n)
{
	int	res;
	int	pow; 

	res = 0;
	pow = intlen(n) - 2;
	while (pow >= 0)
		res += ft_putchar_count(((n / power(10, pow--)) % 10) + 48);
	res += ft_putchar_count(n % 10 + 48);
	if (res != intlen(n))
		return (-1);
	return (res);
}

int	ft_putnbr_iter(int n)
{
	int	res;
	int	pow;
	int	negati;

	res = 0;
	negati = 0;
	if (n == -2147483648)
		return (ft_putstr_count("-2147483648"));
	if (n < 0)
	{
		res += ft_putchar_count('-');
		n = -n;
		negati = 1;
	}
	pow = intlen(n) - 2;
	while (pow >= 0)
		res += ft_putchar_count(((n / power(10, pow--)) % 10) + 48);
	res += ft_putchar_count(n % 10 + 48);
	if (res != intlen(n) + negati)
		return (-1);
	return (res);
}

int	ft_putadr(unsigned long int nbr, char *base)
{
	int		res;
	char	*buff;
	int		i;

	res = 0;
	i = 0;
	if (nbr == 0)
		return (ft_putchar_count('0'));
	buff = malloc(42);
	if (!buff)
		return (-1);
	while (nbr > 0)
	{
		buff[i] = base[nbr % ft_strlen(base)];
		nbr = nbr / ft_strlen(base);
		i++;
	}
	res = i;
	buff[i] = '\0';
	while (--i >= 0)
		if (ft_putchar_count(buff[i]) <= 0)
			return (free(buff), -1);
	free(buff);
	return (res);
}

int	ft_checkadr(unsigned long int n, char *base)
{
	if (!n)
		return (ft_putstr_count("(nil)"));
	else
	{
		write(1, "0x", 2);
		return (ft_putadr(n, base) + 2);
	}
}
