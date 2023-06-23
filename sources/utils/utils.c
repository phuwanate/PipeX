/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:32:20 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/23 17:47:56 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

void	open_file(int proc_id, char *av)
{
	int	in_file;
	int	out_file;

	in_file = 0;
	out_file = 0;
	if (proc_id == 1)
	{
		in_file = open(av, O_RDONLY);
		if (in_file == -1)
			exit(1);
		dup2(in_file, STDIN_FILENO);
		close(in_file);
	}
	else
	{
		out_file = open(av, O_TRUNC | O_WRONLY | O_CREAT, 0644);
		if (out_file == -1)
			exit(1);
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
		exit(1);
	}
}
