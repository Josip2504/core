/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:45:20 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/20 13:09:20 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int ac, char **av)
{
	int i = 0;
	char *s = av[1];
	int f = 0;

	if (ac == 2)
	{
		while (s[i] == 32 || s[i] == '\t')
			i++;
		while (s[i])
		{
			if (s[i] == 32 || s[i] == '\t')
				f = 1;
			if (!(s[i] == 32 || s[i] == '\t'))
			{
				if (f)
					write (1, "   ", 3);
				f = 0;
				write (1, &s[i], 1);
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
