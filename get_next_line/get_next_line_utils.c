/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:50:31 by jsamardz          #+#    #+#             */
/*   Updated: 2024/03/26 16:29:43 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	while (len >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		len--;
		s--;
	}
	return (NULL);
}

int	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}
