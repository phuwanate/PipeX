/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:46:55 by plertsir          #+#    #+#             */
/*   Updated: 2023/07/18 13:01:20 by plertsir         ###   ########.fr       */
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
		free_mem(data, 1);
	i = 0;
	while (i < data->pipe_nb)
	{
		data->pipes[i] = (int *)malloc(2 * sizeof(int));
		if (!data->pipes[i])
			free_mem(data, 1);
		if (pipe(data->pipes[i]))
			free_mem(data, 1);
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
		free_mem(data, 1);
	data->pipe_nb = data->proc - 1;
	data->status = 0;
	open_pipes(data);
	return (data);
}

static void	init_file(t_data *data, int i, int ac, char **av)
{
	data_status(data, i, ac);
	if (data->status == 0 || data->status == 2)
		open_file(i, av, ac);
	close_before(data, i);
}

int	main(int ac, char *av[], char *envp[])
{
	int		i;
	t_data	*data;

	if (ac != 5)
		param_error();
	data = make_struct(ac);
	i = 0;
	while (i < data->proc)
	{
		data->pid[i] = fork();
		if (data->pid[i] == -1)
			fork_error(data);
		if (data->pid[i] == 0)
		{
			init_file(data, i, ac, av);
			get_path(data, &envp[0], get_cmd(data, av[i + 2]));
		}
		i++;
	}
	close_pipe_main(data);
	i = 0;
	while (i < data->proc)
		waitpid(data->pid[i++], &data->status, WUNTRACED);
	free_mem(data, WEXITSTATUS(data->status));
}
