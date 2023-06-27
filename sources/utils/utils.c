/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:32:20 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/27 17:44:09 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void	open_file(int proc_id, char *av, t_data *data)
{
	int	in_file;
	int	out_file;

	in_file = 0;
	out_file = 0;
	if (proc_id == 1)
	{
		in_file = open(av, O_RDONLY);
		if (in_file == -1)
		{
			ft_putstr_fd("result: ", 2);
			perror(NULL);
			exit(1);
		}
		dup2(in_file, STDIN_FILENO);
		close(in_file);
	}
	else
	{
		out_file = open(av, O_TRUNC | O_WRONLY | O_CREAT, 0644);
		if (out_file == -1)
			exit(8);
		dup2(out_file, STDOUT_FILENO);
		close(out_file);
	}
}

int	find_path(const char *s1)
{
	char	*s2;
	int		i;

	s2 = "PATH=";
	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	force_quit(int nb)
{
	if (nb == 0)
		exit(0);
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(9);
	}
}

void	data_status(t_data *data, int nb_proc, int ac)
{
	if (nb_proc == 1)
		data->status = 0;
	else if (nb_proc == ac - 1)
		data->status = 2;
	else
		data->status = 1;
}
