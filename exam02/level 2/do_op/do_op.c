/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:31:17 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/24 15:31:17 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main (int ac, char **av)
{
	int i = 0;
	int a = atoi(av[1]);
	int b = atoi(av[3]);
	int res = 0;

	if (ac == 4)
	{
		if (av[2][i] == '+')
		{
			res = a + b;
			printf("%d", res);
		}
		else if (av[2][i] == '-')
		{
			res = a - b;
			printf("%d", res);
		}
		else if (av[2][0] == '*')
		{
			res = a * b;
			printf("%d", res);
		}
		else if (av[2][i] == '/')
		{
			res = a / b;
			printf("%d", res);
		}
		else if (av[2][i] == '%')
		{
			res = a % b;
			printf("%d", res);
		}
	}
	write (1, "\n", 1);
	return (0);
}