/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:00:30 by plertsir          #+#    #+#             */
/*   Updated: 2023/03/23 13:56:34 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert(char *dst, int nb, int size)
{
	if (nb < 0)
		dst[size + 1] = '\0';
	else
		dst[size--] = '\0';
	while (1)
	{
		if (nb < 0)
		{
			dst[0] = '-';
			nb *= -1;
		}
		if (nb > 9)
		{
			dst[size] = (nb % 10) + '0';
			nb /= 10;
		}
		else
		{
			dst[size] = nb + '0' ;
			break ;
		}
		size--;
	}
	return (dst);
}

static int	count_n(int count)
{
	int		size;

	size = 0;
	if (count < 0)
		count *= -1;
	while (count > 0)
	{
		count = count / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*dst;

	if (n >= 2147483647)
		return (ft_strdup("2147483647"));
	else if (n <= -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	size = count_n(n);
	if (n > 0)
		dst = (char *)malloc((size + 1) * sizeof(char));
	else
		dst = (char *)malloc((size + 2) * sizeof(char));
	if (dst != NULL)
		ft_convert(dst, n, size);
	return (dst);
}
