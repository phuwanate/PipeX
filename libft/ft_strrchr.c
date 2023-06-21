/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:42:16 by plertsir          #+#    #+#             */
/*   Updated: 2023/03/08 21:34:57 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	size_t	len_s;
	size_t	i;

	len_s = ft_strlen(s);
	ptr = (char *)s;
	if (c == '\0')
		return (&ptr[len_s]);
	i = 0;
	while (i <= len_s)
	{
		if (ptr[len_s - i] == (char) c)
			return (&ptr[len_s - i]);
		i++;
	}
	return (NULL);
}
