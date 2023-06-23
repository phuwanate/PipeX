/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:13:53 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/23 11:32:30 by plertsir         ###   ########.fr       */
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
	ft_putendl_fd("Error command not found", 2);
	exit(127);
}

void	param_error(char **split_av)
{
	int	j;

	j = 0;
	while (split_av[j])
	{
		ft_putstr_fd(&(*split_av[j]), 2);
		ft_putstr_fd(": ", 2);
		j++;
	}
	perror(NULL);
	exit(1);
}
