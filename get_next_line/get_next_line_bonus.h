/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:10:48 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/02 16:35:21 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		ft_strrchr(const char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_buffer(char *buff, char *line);
char	*ft_next(int fd, char *buff);
char	*ft_new(int fd, char *stat);

#endif