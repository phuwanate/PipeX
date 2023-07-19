/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:30:04 by plertsir          #+#    #+#             */
/*   Updated: 2023/07/19 15:30:58 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

static void	path_cpy(char *dst, const char *src)
{
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(src);
	i = 0;
	while (i < len_src)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

static size_t	len_spl_av(char **spl_av)
{
	size_t	i;

	i = 0;
	while (spl_av[i])
		i++;
	return (i);
}

void	go_exec(t_data *data, char *path, char **spl_av, char **envp)
{
	char	**path_exec;
	size_t	len_av;
	size_t	len_path;
	int		i;

	errno = 0;
	len_av = len_spl_av(spl_av);
	len_path = ft_strlen(path);
	path_exec = ft_calloc(len_av + 1, sizeof(char *));
	path_exec[0] = (char *)malloc(len_path + 1 * sizeof(char));
	path_cpy(&(*path_exec[0]), &path[0]);
	i = 1;
	while (spl_av[i])
	{
		len_av = ft_strlen(spl_av[i]);
		path_exec[i] = (char *)malloc(len_av + 1 * sizeof(char));
		path_cpy(path_exec[i], spl_av[i]);
		i++;
	}
	execve(path_exec[0], path_exec, envp);
	free_2d(path_exec);
	free_mem(data, 1);
}
