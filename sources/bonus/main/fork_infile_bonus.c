/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_infile_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:37:31 by plertsir          #+#    #+#             */
/*   Updated: 2023/07/19 15:18:07 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex_bonus.h"
#include "get_next_line_bonus.h"
#include <unistd.h>

static void	close_before(t_data *data, int id)
{
	if (data->status == 0)
		close_infile(data, id);
	else if (data->status == 1)
		close_child(data, id);
	else if (data->status == 2)
		close_outfile(data, id);
}

static void	init_file(t_data *data, int i, int ac, char **av)
{
	data_status(data, i, ac);
	if (data->status == 0 || data->status == 2)
		open_file(i, av, ac);
	close_before(data, i);
}

void	normal_infile(t_data *data, int ac, char **av, char **envp)
{
	int	i;

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
}
