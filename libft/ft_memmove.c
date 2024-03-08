/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:08:46 by jsamardz          #+#    #+#             */
/*   Updated: 2024/03/07 12:51:05 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;
	size_t	i;

	dest = (char *) dst;
	source = (char *) src;
	i = 0;
	if (dest > source)
	{
		while (len > 0)
		{
			dest[len] = source[len];
			len--;
		}
	}
	else
	{
		while (len > i)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}
