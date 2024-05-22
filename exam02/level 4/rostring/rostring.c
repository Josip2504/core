/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:10:30 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/21 14:35:10 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_w(char *s, char *e)
{
	while (s < e)
	{
		write (1, s, 1);
		s++;
	}
}

int main (int ac, char **av)
{
	char *s;
	char *start;
	char *end;
	
	if (ac > 1)
	{
		s = av[1];
		while (*s == 32 || *s == '\t')
			s++;
		start = s;
		while (*s && *s != 32 && *s != '\t')
			s++;
		end = s;
		while (*s == 32 || *s == '\t')
			s++;
		if (*s)
		{
			while (*s)
			{
				if (*s == 32 || *s == '\t')
				{
					while (*s == 32 || *s == '\t')
						s++;
					if (*s)
						write (1, " ", 1);
				}
				else
				{
					write (1, s, 1);
					s++;
				}
			}
			write (1, " ", 1);
		}
		ft_w(start, end);
	}
	write (1, "\n", 1);
	return (0);
}