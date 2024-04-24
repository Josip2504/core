/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:20:23 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/24 15:20:23 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_low(char s)
{
	s += 32;
	write (1, &s, 1);
}

int main (int ac, char **av)
{
	int i = 0;
	char *s = av[1];

	if (ac == 2)
	{
		while (s[i])
		{
			while (s[i] >= 'a' && s[i] <= 'z')
			{
				write (1, &s[i], 1);
				i++;
			}
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				write(1, "_", 1);
				ft_low(s[i]);
				i++;
			}
		}
	}
	write (1, "\n", 1);
	return (0);
}