/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:43:54 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/22 17:17:10 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <stdio.h>

char	**get_cmd(char *av)
{
	char	**arg_split;

	arg_split = ft_split(av, ' ');

	return (arg_split);
}
