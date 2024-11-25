/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:29:11 by ejonsery          #+#    #+#             */
/*   Updated: 2024/10/23 12:19:52 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*pt;
	t_list	*tmp;

	if (!lst || !*lst || !del)
		return ;
	pt = *lst;
	while (pt)
	{
		tmp = pt->next;
		ft_lstdelone(pt, del);
		pt = tmp;
	}
	*lst = NULL;
}
