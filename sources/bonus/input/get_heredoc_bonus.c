/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:50:26 by plertsir          #+#    #+#             */
/*   Updated: 2023/07/19 11:34:39 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"
#include <stdio.h>

char	*end_doc(char *hay_stack, char *needle)
{
	size_t	i;

	i = 0;
	while (hay_stack[i] && needle[i])
	{
		if (hay_stack[i] != needle[i])
			break ;
		i++;
	}
	if ((hay_stack[i] == '\0') && (needle[i] == '\0'))
		return ("true");
	else
		return (NULL);
}
