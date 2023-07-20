/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:50:26 by plertsir          #+#    #+#             */
/*   Updated: 2023/07/20 12:09:56 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"
#include <stdio.h>

char	*end_doc(char *hay_stack, char *needle)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if (hay_stack[i] != needle[i])
			break ;
		i++;
	}
	if ((hay_stack[i] == '\n') && (needle[i] == '\0'))
		return ("true");
	else
		return (NULL);
}
