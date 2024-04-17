/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:47:37 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/17 15:57:29 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat(char c, int pos)
{
	while (pos >= 0)
	{
		write (1, &c, 1);
		pos--;
	}
}

int main(int ac, char **av)
{
	int i = 0;
	int pos = 0;
	
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i]<= 'z')
			{
				pos = (av[1][i] - 'a');
				repeat(av[1][i], pos);
			}
			else if (av[1][i] >= 'A' && av[1][i]<= 'Z')
			{
				pos = (av[1][i] - 'A');
				repeat(av[1][i], pos);
			}
			else
				write (1, &av[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}