/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:50:42 by jsamardz          #+#    #+#             */
/*   Updated: 2024/03/26 16:38:54 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next(char *stat)
{
	int		i;
	int		leftover;
	char	*line;

	i = 0;
	leftover = 0;
	while (stat[i] != '\n' && stat[i])
		i++;
	if (!stat[i])
	{
		free(stat);
		return (NULL);
	}
	line = malloc((ft_strlen(stat) + 1 - i) * sizeof(char));
	i++;
	while (stat[i])
		line[leftover++] = stat[i++];
	free (stat);
	return (line);
}

char	*ft_line(char *stat)
{
	char	*size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stat[i])
		return (NULL);
	while (stat[i] != '\n' && stat[i])
		i++;
	size = malloc(i + 2 * sizeof(char));
	while (stat[i] != '\n' && stat[i])
	{
		size[j] = stat[i];
		i++;
		j++;
	}
	if (stat[i] == '\n' && stat[i])
		size[++j] = '\n';
	return (size);
}

char	*ft_buffer(int fd, char *stat)
{
	char	*buffer;
	int		i;

	i = 1;
	if (!stat)
		stat = malloc(1 * 1);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = 0;
		free (buffer);
		free (stat);
		if (ft_strrchr(buffer, '\n'))
			break ;
	}
	free (buffer);
	return (buffer);
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
	return (line);
}
