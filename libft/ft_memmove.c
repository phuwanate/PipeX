/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:58:35 by plertsir          #+#    #+#             */
/*   Updated: 2023/03/08 16:05:43 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	char		*last_s;
	char		*last_d;

	d = dst;
	s = src;
	if (src != NULL || dst != NULL)
	{
		if (d < s)
			ft_memcpy(d, s, len);
		else
		{
			last_s = (void *)s + (len - 1);
			last_d = d + (len - 1);
			while (len--)
				*last_d-- = *last_s--;
		}
	}
	return (dst);
}
