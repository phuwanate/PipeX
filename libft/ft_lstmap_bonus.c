/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:34:24 by plertsir          #+#    #+#             */
/*   Updated: 2023/03/08 18:17:25 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*currentnode;
	t_list		*new_list;

	if (lst == NULL || del == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		currentnode = ft_lstnew((*f)(lst->content));
		if (!currentnode)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}	
		ft_lstadd_back(&new_list, currentnode);
		lst = lst->next;
	}
	return (new_list);
}
