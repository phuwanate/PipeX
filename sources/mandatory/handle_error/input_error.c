/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:13:53 by plertsir          #+#    #+#             */
/*   Updated: 2023/07/18 10:49:00 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "stdlib.h"
#include <stdio.h>

void	param_error(void)
{
	ft_putstr_fd("Error parameters should be like : \n", 2);
	ft_putstr_fd("$> ./pipex infile cmd1 cmd2 outfile\n", 2);
	exit(1);
}

void	cmd_err(t_data *data, char *spl_av)
{
	ft_putstr_fd(spl_av, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd("command not found", 2);
	free_mem(data, 127);
}

void	path_error(t_data *data, char *path)
{
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd("No such file or directory", 2);
	free_mem(data, 127);
}

void	file_error(char *file)
{
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	perror(NULL);
	exit(1);
}

void	fork_error(t_data *data)
{
	close_pipe_main(data);
	free_mem(data, 1);
}
