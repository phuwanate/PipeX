/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_heredoc_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:19:24 by plertsir          #+#    #+#             */
/*   Updated: 2023/07/19 15:18:11 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "pipex_bonus.h"
#include "get_next_line_bonus.h"
#include <unistd.h>
#include <fcntl.h>

static int	init_fd(int status)
{
	int	fd;

	if (status == 1)
	{
		fd = open("temp.txt", O_RDONLY);
		if (fd == -1)
			file_error("temp.txt");
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	return (0);
}

static void	open_heredoc(char **av)
{
	size_t	len_doc;
	char	*in_doc;
	int		fd;

	init_fd(0);
	fd = open("temp.txt", O_TRUNC | O_WRONLY | O_CREAT, 0644);
	while (1)
	{
		in_doc = get_next_line(0);
		len_doc = ft_strlen(in_doc);
		if (ft_strncmp(in_doc, av[2], ft_strlen(av[2])) == 0)
		{
			free(in_doc);
			break ;
		}
		write(fd, in_doc, len_doc);
		free(in_doc);
	}
	close(fd);
	init_fd(1);
}

static void	close_before_heredoc(t_data *data, int id)
{
	if (data->status == 0)
		close_infile(data, id);
	else if (data->status == 1)
		close_child(data, id);
	else if (data->status == 2)
		close_outfile(data, id);
}

static void	init_heredoc(t_data *data, int i, int ac, char **av)
{
	heredoc_status(data, i, ac);
	if (data->status == 2)
		out_heredoc(av, ac);
	close_before_heredoc(data, i);
}

void	heredoc_infile(t_data *data, int ac, char **av, char **envp)
{
	int		i;

	i = 0;
	open_heredoc(av);
	while (i < data->proc)
	{
		data->pid[i] = fork();
		if (data->pid[i] == -1)
			fork_error(data);
		if (data->pid[i] == 0)
		{
			init_heredoc(data, i, ac, av);
			get_path(data, &envp[0], get_cmd(data, av[i + 3]));
		}
		i++;
	}
}
