/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipe_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:09:36 by plertsir          #+#    #+#             */
/*   Updated: 2023/07/18 13:03:04 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	close_infile(t_data *data, int id)
{
	int	j;

	(void)id;
	j = 0;
	while (j < data->pipe_nb)
	{
		if (j != 0)
			close(data->pipes[j][1]);
		close(data->pipes[j][0]);
		j++;
	}
	dup2(data->pipes[0][1], STDOUT_FILENO);
	close(data->pipes[0][1]);
}

void	close_child(t_data *data, int id)
{
	int	j;

	j = 0;
	while (j < data->pipe_nb)
	{
		if (j != id - 1)
			close(data->pipes[j][0]);
		if (j != id)
			close(data->pipes[j][1]);
		j++;
	}
	dup2(data->pipes[id - 1][0], STDIN_FILENO);
	if (data->pipe_nb > 1)
	{
		dup2(data->pipes[id][1], STDOUT_FILENO);
		close(data->pipes[id][1]);
	}
	close(data->pipes[id - 1][0]);
}

void	close_outfile(t_data *data, int id)
{
	int	j;

	j = 0;
	while (j < data->pipe_nb)
	{
		if (j != id - 1)
			close(data->pipes[j][0]);
		close(data->pipes[j][1]);
		j++;
	}
	dup2(data->pipes[id - 1][0], STDIN_FILENO);
	close(data->pipes[id - 1][0]);
}

void	close_pipe_main(t_data *data)
{
	int	j;

	j = 0;
	while (j < data->pipe_nb)
	{
		close(data->pipes[j][0]);
		close(data->pipes[j][1]);
		j++;
	}
}