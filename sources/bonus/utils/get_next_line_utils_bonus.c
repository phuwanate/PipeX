/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:34:37 by plertsir          #+#    #+#             */
/*   Updated: 2023/03/20 18:00:33 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	size_t	len_s;
	size_t	i;

	len_s = ft_strlen(s);
	ptr = (char *)s;
	if (c == '\0')
		return (&ptr[len_s]);
	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (char)c)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	char	*ptr;
	char	*result;
	size_t	size;

	size = 0;
	ptr = (char *)s1;
	size = ft_strlen(ptr);
	dst = (char *)malloc(size + 1 * sizeof(char));
	result = dst;
	if (dst)
	{
		while (*ptr != '\0')
		{
			*dst++ = *ptr++;
		}
		*dst = '\0';
	}
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (ft_strdup(""));
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (ptr != NULL)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			ptr[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j] != '\0')
		{
			ptr[i + j] = s2[j];
			j++;
		}
		ptr[i + j] = '\0';
	}
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	j;
	size_t	n;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start || len == 0)
		return (ft_strdup(""));
	n = ft_strlen(&s[start]);
	if (len > n)
		dst = (char *)malloc((n + 1) * sizeof(char));
	else
		dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (i >= start && j < len)
			dst[j++] = s[i];
	}
	dst[j] = '\0';
	return (dst);
}
