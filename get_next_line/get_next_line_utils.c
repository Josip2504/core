/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:50:31 by jsamardz          #+#    #+#             */
/*   Updated: 2024/03/28 15:30:56 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	chr;

	len = 0;
	if (!s)
		return (-1);
	chr = (unsigned char)c;
	while (s[len] != '\0')
	{
		if (s[len] == chr)
			return (len);
		len++;
	}
	if (chr == '\0')
		return (len);
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*sub;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	i = 0;
	if (len > slen)
		len = slen;
	if (start >= slen)
	{
		sub = (char *)malloc(1);
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	sub = (char *)malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	while (i++ < start)
		s++;
	ft_strlcpy(sub, s, len + 1);
	return (sub);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			srclen;

	i = 0;
	if (src == NULL)
		return (0);
	srclen = ft_strlen(src);
	if ((int)size < 0)
		size = srclen + 1;
	if (size >= 2 && srclen != 0)
	{
		while (i < size - 1)
		{
			if (i < srclen)
				dst[i] = src[i];
			else if (i == srclen)
				dst[i] = '\0';
			i++;
		}
	}
	if (size != 0)
		dst[i] = '\0';
	return (srclen);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	char			*p;

	if (size < ft_strlen(dest))
		return (ft_strlen(src) + size);
	p = dest + ft_strlen(dest);
	i = ft_strlen(dest);
	while (i < size - 1 && *src != '\0' && size >= 2)
	{
		*p = *src;
		src++;
		p++;
		i++;
	}
	if (size != 0)
		*p = '\0';
	return (ft_strlen(dest) + ft_strlen(src));
}
