/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:50:42 by jsamardz          #+#    #+#             */
/*   Updated: 2024/03/27 15:28:24 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *stat)
{
	char	*res;
	int		i;

	i = 0;
	if (!stat[i] || !*stat)
		return (NULL);
	while (stat[i] != '\n' && stat[i])
		i++;
	res = (char *)malloc((i + 2) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (stat[i] != '\n' && stat[i])
	{
		res[i] = stat[i];
		i++;
	}
	if (stat[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*ft_next(char *stat)
{
	int		i;
	int		leftover;
	char	*line;

	i = 0;
	leftover = 0;
	if (!stat || !*stat)
	{
		free(stat);
		return (NULL);
	}
	while (stat[i] != '\n' && stat[i] != '\0')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stat[i] && stat[i] != '\n')
		line[leftover++] = stat[i++];
	line[leftover] = '\0';
	free(stat);
	return (line);
}

char	*ft_buffer(int fd, char *stat)
{
	char	*buffer;
	char	*temp;
	int		i;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	i = read(fd, buffer, BUFFER_SIZE);
	if (i < 0)
	{
		free (buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	if (!stat)
	{
		stat = malloc(1);
		if (!stat)
		{
			free (buffer);
			return (NULL);
		}
		stat[0] = '\0';
	}
	while (ft_strrchr(stat, '\n') == NULL && i > 0)
	{
		
		temp = ft_strjoin(stat, buffer);
		if (!temp)
		{
			free(buffer);
			return (NULL);
		}
		stat = temp;
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free (buffer);
			free (stat);
			return (NULL);
		}
		buffer[i] = '\0';
	}
	free(buffer);
	return (stat);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stat;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stat = ft_buffer(fd, stat);
	if (!stat)
		return (NULL);
	line = ft_line(stat);
	stat = ft_next(stat);
	free(stat);
	return (line);
}
