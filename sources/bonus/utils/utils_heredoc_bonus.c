/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_heredoc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:44:07 by plertsir          #+#    #+#             */
/*   Updated: 2023/07/19 16:13:57 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex_bonus.h"
#include "get_next_line_bonus.h"
#include <stdio.h>

int	is_heredoc(char **av, int ac)
{
	size_t	len_av;

	len_av = ft_strlen(av[1]);
	if (ft_strnstr(av[1], "here_doc", len_av) != NULL)
	{
		if (ac < 6)
		{
			ft_putstr_fd("Error parameter should be like :\n\n", 2);
			ft_putstr_fd("$> ./pipex here_doc LIMITER ", 2);
			ft_putstr_fd("cmd1 cmd2...cmd(n) outfile\n\n", 2);
			exit(1);
		}
		return (1);
	}
	else
		return (0);
}
