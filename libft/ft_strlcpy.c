/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:51:49 by jsamardz          #+#    #+#             */
/*   Updated: 2024/03/08 15:55:25 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	size_t	srclen;
	int		i;

	srclen = ft_strlen(src);
	i = 0;
	if (srclen + 1 < size)
	{
		while (i < srclen + 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else if (size < srclen)
	{
		while (i + 1 < size)
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (srclen);
}
