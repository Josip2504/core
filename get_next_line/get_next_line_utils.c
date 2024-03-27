/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:50:31 by jsamardz          #+#    #+#             */
/*   Updated: 2024/03/27 15:02:58 by jsamardz         ###   ########.fr       */
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

char	*ft_strjoin(char *stat, char *buff)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!stat)
	{
		stat = (char *)malloc(1 * sizeof(char));
		if (!stat)
			return (NULL);
		stat[0] = '\0';
	}
	if (!stat || !buff)
		return (NULL);
	res = (char *)malloc(
			(ft_strlen(stat) + ft_strlen(buff) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (stat[i] != '\0')
	{
		res[i] = stat[i];
		i++;
	}
	j = 0;
	while (buff[j] != '\0')
	{
		res[i + j] = buff[j];
		j++;
	}
	res[i + j] = '\0';
	free(stat);
	return (res);
}
