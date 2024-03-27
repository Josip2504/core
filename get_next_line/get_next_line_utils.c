/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:50:31 by jsamardz          #+#    #+#             */
/*   Updated: 2024/03/27 10:42:33 by jsamardz         ###   ########.fr       */
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
		stat[0] = '\0';
	}
	if (!stat || !buff)
		return (NULL);
	res = (char *)malloc(
			(ft_strlen(stat) + ft_strlen(buff) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	if (stat)
		while (stat[++i] != '\n')
			res[i] = stat[i];
	while (buff[j] != '\0')
		res[i++] = buff[j++];
	res[ft_strlen(stat) + ft_strlen(buff)] = '\0';
	free(stat);
	return (res);
}
