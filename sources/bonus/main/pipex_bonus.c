/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:46:55 by plertsir          #+#    #+#             */
/*   Updated: 2023/07/18 18:38:52 by plertsir         ###   ########.fr       */
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
#include "pipex_bonus.h"

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

static t_data	*make_struct(int heredoc_status, int ac)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (heredoc_status == 0)
		data->proc = ac - 3;
	else
		data->proc = ac - 4;
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

int	main(int ac, char *av[], char *envp[])
{
	int		i;
	int		heredoc_status;
	t_data	*data;

	if (ac < 5)
		param_error();
	heredoc_status = is_heredoc(av);
	data = make_struct(heredoc_status, ac);
	if (heredoc_status == 0)
		normal_infile(data, ac, av, envp);
	else
		heredoc_infile(data, ac, av, envp);
	close_pipe_main(data);
	i = 0;
	while (i < data->proc)
		waitpid(data->pid[i++], &data->status, WUNTRACED);
	unlink("temp.txt");
	free_mem(data, WEXITSTATUS(data->status));
}
