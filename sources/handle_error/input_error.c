/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:13:53 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/30 18:35:56 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "stdlib.h"
#include <stdio.h>

void	cmd_err(char *split_av)
{
	ft_putstr_fd(split_av, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd("command not found", 2);
	exit(127);
}

void	param_error(char **split_av)
{
	int	j;

	(void)split_av;
	j = 0;
	while (split_av[j])
	{
		ft_putstr_fd(&(*split_av[j]), 2);
		ft_putstr_fd(": ", 2);
		j++;
	}
	perror(NULL);
	exit(127);
}

void	path_error(char *path)
{
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd("No such file or directory", 2);
	exit(127);
}

void	infile_error(char *in_file)
{
	ft_putstr_fd(in_file, 2);
	ft_putstr_fd(": ", 2);
	perror(NULL);
	exit(1);
}

void	fork_error(t_data *data)
{
	close_pipe_main(data);
	free_mem(data);
	exit(1);
}
