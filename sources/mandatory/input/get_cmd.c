/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:43:54 by plertsir          #+#    #+#             */
/*   Updated: 2023/07/19 15:53:29 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <stdio.h>

static void	path_cmd_error(t_data *data, char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		ft_putstr_fd(path[i], 2);
		if (path[i + 1] != NULL)
			ft_putstr_fd(" ", 2);
		i++;
	}
	ft_putstr_fd(": ", 2);
	ft_putendl_fd("No such file or directory", 2);
	free_2d(path);
	free_mem(data, 127);
}

char	**get_cmd(t_data *data, char *av)
{
	char	**arg_split;

	arg_split = ft_split(av, ' ');
	if (arg_split == NULL)
		free_mem(data, 1);
	if (ft_strchr(arg_split[0], '/') != NULL)
	{
		if (access(arg_split[0], X_OK) == -1)
			path_cmd_error(data, arg_split);
	}
	return (arg_split);
}
