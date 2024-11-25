/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:19:02 by ejonsery          #+#    #+#             */
/*   Updated: 2024/10/23 12:09:46 by ejonsery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*fst_iter(t_list *lst, void *(*f)(void *))
{
	void	*f_tmp;

	f_tmp = f(lst->content);
	if (!f_tmp)
		return (NULL);
	return (f_tmp);
}

static t_list	*ft_maper(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;
	t_list	*last_elem;
	void	*f_tmp;

	f_tmp = fst_iter(lst, f);
	res = ft_lstnew(f_tmp);
	if (!res)
		return (ft_lstclear(&res, del), del(f_tmp), NULL);
	lst = lst->next;
	last_elem = res;
	while (lst)
	{
		f_tmp = f(lst->content);
		if (!f_tmp)
			return (ft_lstclear(&res, del), NULL);
		tmp = ft_lstnew(f_tmp);
		if (!tmp)
			return (ft_lstclear(&res, del), del(f_tmp), NULL);
		last_elem->next = tmp;
		last_elem = last_elem->next;
		lst = lst->next;
	}
	return (res);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;

	if (!lst || !f || !del)
		return (NULL);
	res = ft_maper(lst, f, del);
	return (res);
}
