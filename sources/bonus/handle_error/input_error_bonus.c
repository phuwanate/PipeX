/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:13:53 by plertsir          #+#    #+#             */
/*   Updated: 2023/07/20 20:54:31 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"
#include "stdlib.h"
#include <string.h>
#include <errno.h>
#include <stdio.h>

void	param_error(void)
{
	ft_putstr_fd("Error parameters should be like : \n\n", 2);
	ft_putstr_fd("$> ./pipex infile cmd1 cmd2...cmd(n) outfile \nor\n", 2);
	ft_putstr_fd("$> ./pipex here_doc LIMITER ", 2);
	ft_putstr_fd("cmd1 cmd2...cmd(n) outfile\n\n", 2);
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
	ft_putendl_fd(strerror(errno), 2);
	exit(1);
}

void	fork_error(t_data *data)
{
	close_pipe_main(data);
	free_mem(data, 1);
}
