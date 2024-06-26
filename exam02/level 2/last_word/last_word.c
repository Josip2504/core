/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:52:33 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/20 12:43:48 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int ac, char **av)
{
	int i = 0;
	int j = 0;

	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] == 32 && av[1][i + 1] >= 33 && av[1][i] <= 126)
				j = i + 1;
			i++;
		}
		while (av[1][j] >= 33 && av[1][j] <= 126)
		{
			write (1, &av[1][j], 1);
			j++;
		}
	}
	write (1, "\n", 1);
	return (0);
}