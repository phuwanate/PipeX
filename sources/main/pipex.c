/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:46:55 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/21 16:26:34 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>
#include "libft.h"
#include "pipex.h"


static char	**split_path(char *str, char c)
{
	char	**path_split;
	int		i;

	path_split = ft_split(str, c);
	if (!path_split)
		force_quit(1);
	i = 0;
	return (path_split);
}

static void	get_cmd(char **av)
{
	char	**arg_split;
	int		i;

	arg_split = ft_split(av[1], ' ');
	i = 0;
}

static void	get_path(char **envp, char **av)
{
	int		i;
	int		status;
	size_t	len;
	char	*path;
	char	**path2;

	i = 0;
	while (*envp)
	{
		len = ft_strlen(*envp);
		status = find_path(*envp);
		if (status == 1)
			break ;
		envp++;
	}
	path = ft_substr(*envp, 5, len);
	path2 = split_path(path, ':');
	path = ft_strjoin(*path2, "/");
	path = ft_strjoin("/bin/", *av);
	path2 = split_path(path, ' ');
	execve(path2[0], path2, NULL);
	while (path2[i])
		printf("%s\n", path2[i++]);
}

int	main(int ac, char *av[], char *envp[])
{
	if (ac > 2)
	{
		get_cmd(&av[0]);
		get_path(&envp[0], &av[1]);
	}
}
