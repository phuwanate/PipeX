/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:42:38 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/30 17:49:23 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

char	**split_path(char *str, char c)
{
	char	**path_split;
	int		i;

	path_split = ft_split(str, c);
	if (!path_split)
		force_quit(1);
	i = 0;
	return (path_split);
}

static void	check_slash(char *cmd, char **split_av, char **envp)
{
	if (ft_strchr(cmd, '/') != NULL)
	{
		if (access(cmd, X_OK) != -1)
			go_exec(cmd, split_av, envp);
		else
			path_error(cmd);
	}
}

static void	ext_path(char *path_exec, char **envp, size_t len, char **split_av)
{
	char	*path;
	char	*tmp;
	char	**path2;
	int		i;

	errno = 0;
	check_slash(*split_av, split_av, envp);
	path = ft_substr(path_exec, 5, len);
	path2 = split_path(path, ':');
	free(path);
	path = NULL;
	i = 0;
	while (path2[i])
	{	
		tmp = ft_strjoin(path2[i], "/");
		path = ft_strjoin(tmp, *split_av);
		free(tmp);
		if (access(path, X_OK) != -1)
			go_exec(&path[0], &split_av[0], envp);
		free(path);
		path = NULL;
		i++;
	}
	free_2d(path2);
	if (errno != 0)
		cmd_err(*split_av);
}

void	get_path(char **envp, char **split_av)
{
	int		i;
	int		status;
	char	*path_exec;
	size_t	len;

	i = 0;
	status = 0;
	path_exec = NULL;
	while (envp[i])
	{
		len = ft_strlen(envp[i]);
		status = find_path(envp[i]);
		if (status == 1)
		{
			path_exec = envp[i];
			break ;
		}
		i++;
	}
	if (status == 0)
		path_error(*split_av);
	ext_path(path_exec, envp, len, split_av);
	free_2d(split_av);
}
