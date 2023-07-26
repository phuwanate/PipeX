/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:42:38 by plertsir          #+#    #+#             */
/*   Updated: 2023/07/25 09:53:30 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

static void	free_path(char *path)
{
	free(path);
	path = NULL;
}

static char	**split_path(t_data *data, char *path, char **av)
{
	char	**path_split;

	path_split = ft_split(path, ':');
	if (!path_split)
	{
		free_path(path);
		free_2d(av);
		free_mem(data, 1);
	}
	return (path_split);
}

static void	check_slash(t_data *data, char *cmd, char **spl_av, char **envp)
{
	if (ft_strchr(cmd, '/') != NULL)
	{
		if (access(cmd, X_OK) != -1)
			go_exec(data, cmd, spl_av, envp);
		else if (errno == 13)
		{
			ft_putstr_fd(*spl_av, 2);
			ft_putstr_fd(": ", 2);
			ft_putendl_fd(strerror(errno), 2);
			free_2d(spl_av);
			free_mem(data, 126);
		}
		else
			path_error(data, spl_av);
	}
}

static void	ext_path(t_data *data, char *path_exec, char **envp, char **spl_av)
{
	char	*path;
	char	*tmp;
	char	**path2;
	int		i;

	errno = 0;
	check_slash(data, *spl_av, spl_av, envp);
	path = ft_substr(path_exec, 5, data->len_av);
	path2 = split_path(data, path, spl_av);
	free_path(path);
	i = 0;
	while (path2[i])
	{
		tmp = ft_strjoin(path2[i], "/");
		path = ft_strjoin(tmp, *spl_av);
		free(tmp);
		if (access(path, X_OK) != -1)
			go_exec(data, &path[0], &spl_av[0], envp);
		free_path(path);
		i++;
	}
	free_2d(path2);
	if (errno != 0)
		cmd_err(data, spl_av);
}

void	get_path(t_data *data, char **envp, char **spl_av)
{
	int		i;
	int		status;
	char	*path_exec;

	i = 0;
	status = 0;
	path_exec = NULL;
	while (envp[i])
	{
		data->len_av = ft_strlen(envp[i]);
		status = find_path(envp[i]);
		if (status == 1)
		{
			path_exec = envp[i];
			break ;
		}
		i++;
	}
	if (status == 0)
		path_error(data, spl_av);
	ext_path(data, path_exec, envp, spl_av);
}
