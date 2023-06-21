/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:36:37 by plertsir          #+#    #+#             */
/*   Updated: 2023/06/21 15:51:56 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkmalloc(int sub_s, char **ptr)
{
	if (!ptr)
	{
		while (sub_s > 0)
		{
			sub_s--;
			free(ptr[sub_s]);
		}
		free(ptr);
		return (1);
	}
	return (0);
}

static int	count_char(char const *s, char c, char **ptr)
{
	int	sub_w;

	sub_w = 0;
	while (s[sub_w] != c && s[sub_w] != '\0')
		sub_w++;
	*ptr = malloc((sub_w + 1) * sizeof(char));
	return (sub_w);
}

static int	ft_countword(char const *s, char c)
{
	int		i;
	int		count;
	int		cap;

	cap = 1;
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
			cap = 1;
		else
			cap = 0;
		if ((cap == 1) && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			count += 1;
			cap = 0;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		sub_s;
	int		sub_w;

	if (s == NULL)
		return (NULL);
	ptr = ft_calloc((ft_countword(s, c) + 2), sizeof(char *));
	if (!ptr)
		return (NULL);
	sub_s = 0;
	while (*s != '\0')
	{
		if (*s != c && *s != '\0')
		{
			sub_w = count_char(s, c, &ptr[sub_s]);
			if (ft_checkmalloc(sub_s, ptr) == 1)
				return (NULL);
			ft_strlcpy (ptr[sub_s], s, sub_w + 1);
			s += sub_w;
			sub_s++;
		}
		else
			s++;
	}
	return (ptr);
}
