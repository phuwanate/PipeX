/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:46:55 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/23 18:34:32 by plertsir         ###   ########.fr       */
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

static void	**open_pipes(t_data *data)
{
	int	i;

	data->pipes = malloc(data->pipe_nb * sizeof(int *));
	if (!data->pipes)
		exit(1);
	i = 0;
	while (i < data->pipe_nb)
	{
		data->pipes[i] = (int *)malloc(2 * sizeof(int));
		if (!data->pipes[i])
			exit(2);
		if (pipe(data->pipes[i]))
			exit(3);
		i++;
	}
	return (0);
}

static t_data	*make_struct(int ac)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->pipe_nb = ac - 4;
	if (!data)
		exit(1);
	data->pid = malloc((ac - 3) * sizeof(int));
	if (!(data->pid))
	{
		free(data->pid);
		exit(1);
	}
	return (data);
}

int	main(int ac, char *av[], char *envp[])
{
	int		i;
	t_data	*data;

	data = make_struct(ac);
	open_pipes(data);
	i = 1;
	while (av[i])
	{
		data->pid[i - 1] = fork();
		if (data->pid[i - 1] == 0)
		{
			if (i == 1 || i == ac - 1)
				open_file(i, av[i]);
			if (i != 1 && i != ac - 1)
				get_path(&envp[0], get_cmd(av[i]));
			return 0;
		}
		i++;
	}
	return (0);
}


//created child + parent 
//need to pipe in child