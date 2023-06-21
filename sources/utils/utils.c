/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:32:20 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/21 13:41:16 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

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
