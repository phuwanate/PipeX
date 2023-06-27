/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:09:36 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/27 18:49:01 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	close_infile(t_data *data, int id)
{
	int	j;

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
		dprintf(2, "%d\n", id);
		if (j != id - 1)
			close(data->pipes[j][0]);
		if (j != id)
			close(data->pipes[j][1]);
		j++;
		dprintf(2, "%d again\n", id);
	}
	dprintf(2,"try to read the pipe [%d]std in\n", id - 1);
	dup2(data->pipes[id - 1][0], STDIN_FILENO); //--->here
	if(data->status == 2)
		return;
	dprintf(2,"try to read the pipe [%d]std out\n", id);
	dup2(data->pipes[id][1], STDOUT_FILENO);
	close(data->pipes[id - 1][0]);
	close(data->pipes[id][1]);
	dprintf(2, "%d againnnnnnn", id);
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
	dup2(data->pipes[id][0], STDIN_FILENO);
	close(data->pipes[id][0]);
}
