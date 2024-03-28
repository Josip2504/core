/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:50:42 by jsamardz          #+#    #+#             */
/*   Updated: 2024/03/28 15:24:21 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buffer(char *buff, char *line)
{
	char	*newbuff;
	int		len;

	if (!buff || !line)
		return (buff);
	len = ft_strlen(line);
	if ((int)ft_strlen(buff) == len)
	{
		free(buff);
		return (NULL);
	}
	newbuff = ft_substr(buff, len, ft_strlen(buff) - len);
	free(buff);
	return (newbuff);
}

char	*ft_next(int fd, char *buff)
{
	char	*s;
	char	*newbuff;
	id_t	nlen;

	s = ft_new(fd);
	if (!s)
		return (NULL);
	if (!s[0])
	{
		free(s);
		return (buff);
	}
	if (!buff)
		return (s);
	nlen = ft_strlen(buff) + ft_strlen(s);
	newbuff = malloc(nlen + 1);
	if (!newbuff)
		return (NULL);
	ft_strlcpy(newbuff, buff, nlen + 1);
	ft_strlcat(newbuff, s, nlen + 1);
	free(buff);
	free(s);
	return (newbuff);
}

char	*ft_new(int fd)
{
	char	*s;
	int		i;

	s = malloc(BUFFER_SIZE + 1);
	if (!s)
		return (NULL);
	i = read(fd, s, BUFFER_SIZE);
	if (i < 0)
	{
		free(s);
		return (NULL);
	}
	s[i] = '\0';
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stat[4096];
	size_t		olen;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	if ((int)ft_strrchr(stat[fd], '\n') == -1)
	{
		olen = ft_strlen(stat[fd]);
		stat[fd] = ft_next(fd, stat[fd]);
		if (olen == ft_strlen(stat[fd]) && stat[fd])
			line = ft_substr(stat[fd], 0, ft_strlen(stat[fd]));
	}
	if (!stat[fd])
		return (NULL);
	if (!line && (int)ft_strrchr(stat[fd], '\n') != -1)
		line = ft_substr(stat[fd], 0, (size_t)ft_strrchr(stat[fd], '\n') + 1);
	if (line)
	{
		stat[fd] = ft_buffer(stat[fd], line);
		return (line);
	}
	return (get_next_line(fd));
}
