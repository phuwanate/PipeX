/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:33:31 by plertsir          #+#    #+#             */
/*   Updated: 2023/03/08 16:05:09 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list		*currentnode;

	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		currentnode = lst;
		f(currentnode->content);
		lst = lst->next;
	}
}
