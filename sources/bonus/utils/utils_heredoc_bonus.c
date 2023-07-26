/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_heredoc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:44:07 by plertsir          #+#    #+#             */
/*   Updated: 2023/07/25 09:51:43 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex_bonus.h"
#include "get_next_line_bonus.h"
#include <stdio.h>

static void	not_heredoc(void)
{
	ft_putstr_fd("Error parameter should be like :\n\n", 2);
	ft_putstr_fd("$> ./pipex here_doc LIMITER ", 2);
	ft_putstr_fd("cmd1 cmd2...cmd(n) outfile\n\n", 2);
	exit(1);
}

int	is_heredoc(char **av, int ac)
{
	size_t	len_av;

	len_av = ft_strlen(av[1]);
	if (ft_strnstr(av[1], "here_doc", len_av) != NULL)
	{
		if (ac < 6 || len_av > 8)
			not_heredoc();
		return (1);
	}
	else
		return (0);
}

int	end_doc(char *hay_stack, char *needle)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if (hay_stack[i] != needle[i])
			break ;
		i++;
	}
	if ((hay_stack[i] != '\n') || (needle[i] != '\0'))
		return (1);
	else
		return (0);
}
