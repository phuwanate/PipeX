/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:43:54 by plertsir          #+#    #+#             */
/*   Updated: 2023/07/18 10:19:51 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <stdio.h>

char	**get_cmd(t_data *data, char *av)
{
	char	**arg_split;

	arg_split = ft_split(av, ' ');
	if (arg_split == NULL)
		free_mem(data, 1);
	return (arg_split);
}
