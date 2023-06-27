/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:46:55 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/27 19:14:51 by plertsir         ###   ########.fr       */
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
	dprintf(2, "pipe_nb[%d]\n", data->pipe_nb);
	if (!data->pipes)
		exit(4);
	i = 0;
	while (i < data->pipe_nb)
	{
		data->pipes[i] = (int *)malloc(2 * sizeof(int));
		if (!data->pipes[i])
			exit(5);
		if (pipe(data->pipes[i]))
			exit(6);
		i++;
	}
	dprintf(2, "the pipe is [%d]\n", data->pipes[0][1]);
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
		exit(2);
	data->pid = malloc(data->proc * sizeof(int));
	if (!(data->pid))
	{
		free(data->pid);
		exit(3);
	}
	data->pipe_nb = data->proc - 1;
	data->status = 0;
	return (data);
}

int	main(int ac, char *av[], char *envp[])
{
	int		i;
	t_data	*data;

	data = make_struct(ac);
	open_pipes(data);
	//dprintf(2, "after the pipe is [%d]\n", data->pipes[0][1]);
	i = 0;
	while (i < ac - 3)
	{
		data->pid[i] = fork();
		if (data->pid[i] == -1)
			exit(1);
		if (data->pid[i] == 0)
		{
			data_status(data, i, ac);
			if (data->status == 0 || data->status == 2)
			{
				//dprintf(2, "status is [%d][%s]\n", data->status, av[i]);
				open_file(i + 1, av[i + 1], data);
			}
			dprintf(2,"here<<<<\n");
			close_before(data, i);
			dprintf(2,"next<<<<\n");
			if(data->status == 2)
			{
				get_path(&envp[0], get_cmd(av[i + 2]));
			}
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < data->proc)
		waitpid(data->pid[i++], NULL, WUNTRACED);
}

//created child + parent 
//need to pipe in child