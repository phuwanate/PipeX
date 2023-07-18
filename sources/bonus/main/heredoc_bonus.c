/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:44:07 by plertsir          #+#    #+#             */
/*   Updated: 2023/07/18 16:07:17 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex_bonus.h"
#include "get_next_line_bonus.h"
#include <stdio.h>

int	is_heredoc(char **av)
{
	size_t	len_av;

	len_av = ft_strlen(av[1]);
	if (ft_strnstr(av[1], "here_doc", len_av) != NULL)
		return (1);
	else
		return (0);
}
