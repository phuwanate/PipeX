/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:30:04 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/23 18:19:36 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

void	go_exec(char *path, char **split_av, char **envp)
{
	char	**path_exec;
	size_t	len_av;
	size_t	len_path;
	int		i;

	errno = 0;
	len_av = ft_strlen(*split_av);
	len_path = ft_strlen(path);
	path_exec = ft_calloc(len_av + 2, sizeof(char *));
	path_exec[0] = (char *)malloc(len_path * sizeof(char));
	ft_strlcpy(&(*path_exec[0]), &path[0], len_path + 1);
	i = 1;
	while (split_av[i])
	{
		path_exec[i] = (char *)malloc(ft_strlen(split_av[i]) * sizeof(char));
		ft_strlcpy(&(*path_exec[i]), &(*split_av[i]), len_path + 1);
		i++;
	}
	execve(path_exec[0], path_exec, envp);
	free_2d(path_exec);
	param_error(split_av);
}
