/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:39:20 by jsamardz          #+#    #+#             */
/*   Updated: 2024/03/08 10:12:24 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	srclen;
	unsigned int	destlen;

	i = 0;
	j = 0;
	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	i = destlen;
	if (size == 0 || size <= destlen)
		return (src + srclen);
	while (src[j] && j < size - destlen - 1)
	{
		dest[j] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (destlen + srclen);
}
