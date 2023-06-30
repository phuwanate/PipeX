/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:46:55 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/30 18:36:10 by plertsir         ###   ########.fr       */
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

static void	open_pipes(t_data *data)
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
		{
			free_mem(data);
			exit(1);
		}
		if (pipe(data->pipes[i]))
		{
			free_mem(data);
			exit(1);
		}
		i++;
	}
}

static void	close_before(t_data *data, int id)
{
	if (data->status == 0)
		close_infile(data, id);
	else if (data->status == 1)
		close_child(data, id);
	else if (data->status == 2)
		close_outfile(data, id);
}

static t_data	*make_struct(int ac)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->proc = ac - 3;
	if (!data)
		exit(1);
	data->pid = malloc(data->proc * sizeof(int));
	if (!(data->pid))
	{
		free_mem(data);
		exit(1);
	}
	data->pipe_nb = data->proc - 1;
	data->status = 0;
	return (data);
}

int	main(int ac, char *av[], char *envp[])
{
	int		i;
	int		status;
	t_data	*data;

	data = make_struct(ac);
	open_pipes(data);
	i = 0;
	while (i < data->proc)
	{
		data->pid[i] = fork();
		if (data->pid[i] == -1)
			fork_error(data);
		if (data->pid[i] == 0)
		{
			data_status(data, i, ac);
			if (data->status == 0 || data->status == 2)
				open_file(i, av, ac);
			close_before(data, i);
			get_path(&envp[0], get_cmd(av[i + 2]));
		}
		i++;
	}
	close_pipe_main(data);
	i = 0;
	while (i < data->proc)
		waitpid(data->pid[i++], &status, WUNTRACED);
	free_mem(data);
	exit (WEXITSTATUS(status));
}
