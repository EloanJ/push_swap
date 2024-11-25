/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:53:46 by ejonsery          #+#    #+#             */
/*   Updated: 2024/11/25 15:41:21 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_display(va_list ptr, char c)
{
	if (c == 'c')
		return (ft_putchar_count(va_arg(ptr, int)));
	else if (c == 's')
		return (ft_putstr_count(va_arg(ptr, char *)));
	else if (c == 'p')
		return (ft_checkadr(va_arg(ptr, unsigned long int), \
			"0123456789abcdef"));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_iter(va_arg(ptr, int)));
	else if (c == 'u')
		return (ft_putunsigned_iter(va_arg(ptr, int)));
	else if (c == 'x')
		return (ft_putx(va_arg(ptr, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putx(va_arg(ptr, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar_count('%'));
	else if (c == '\0')
		return (-1);
	if (ft_putchar_count('%') == 1 && ft_putchar_count(c) == 1)
		return (2);
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		total;
	int		tmp;

	va_start(ptr, str);
	i = 0;
	total = 0;
	tmp = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			tmp = ft_display(ptr, str[i + 1]);
			i++;
		}
		else
			tmp = ft_putchar_count(str[i]);
		if (tmp >= 0)
			total += tmp;
		else
			return (-1);
		i++;
	}
	return (total);
}
