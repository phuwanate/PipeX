/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:12:25 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/30 18:28:28 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

void	free_2d(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
}

void	int_free_2d(int **ptr ,int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
}


void	free_mem(t_data *data)
{
	if (data->pipes != NULL)
		int_free_2d(data->pipes, data->pipe_nb);
	if (data->pid != NULL)
		free(data->pid);
	if (data != NULL)
	{
		free(data);
		data = NULL;
	}
}
