/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:51:10 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/24 16:51:10 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	char *s1 = av[1];
	char *s2 = av[2];
	int tab[256] = {0};

	if (ac == 3)
	{
		i = 0;
		while (s2[i])
			tab[(int)s2[i++]] = 1;
		i = 0;
		while (s1[i])
		{
			if (tab[(int)s1[i]] == 1)
			{
				write (1, &s1[i], 1);
				tab[(int)s1[i]] = 2;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}