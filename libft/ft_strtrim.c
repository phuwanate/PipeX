/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:28:16 by plertsir          #+#    #+#             */
/*   Updated: 2023/03/23 13:57:58 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_trim(char const *s, char const *trim)
{
	size_t	i;

	i = -1;
	while (trim[++i])
	{
		if (*s == trim[i])
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	size;
	int		i;
	int		j;

	if (s1 == NULL)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	i = 0;
	while (s1[i] < 32 || check_trim(&s1[i], set) == 1)
	{
		if (s1[i++] == '\0')
			return (ft_strdup(""));
	}
	j = i;
	while (s1[i] != '\0')
		i++;
	while (s1[i] == '\0' || check_trim(&s1[i], set) == 1)
		i--;
	size = (i - j + 1) + 1;
	s2 = (char *)malloc(size * sizeof(char));
	if (s2 != NULL)
		ft_strlcpy(s2, &s1[j], size);
	return (s2);
}
