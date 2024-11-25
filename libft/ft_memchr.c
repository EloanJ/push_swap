/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:50:58 by ejonsery          #+#    #+#             */
/*   Updated: 2024/10/22 15:22:59 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cst_s;

	i = 0;
	cst_s = (unsigned char *)s;
	while (i < n)
	{
		if (cst_s[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
