/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:13:01 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/27 12:37:36 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[])
{
	int i = 1;
	int num;

	if (ac == 2)
	{
		num = atoi(av[1]);
		if (num == 1)
			printf("1");
		while (num >= ++i)
		{
			if (num % i == 0)
			{
				printf("%d", i);
				if (i == num)
					break ;
				printf("*");
				num /= i;
				i = 1;
			}
		}
	}
	printf("\n");
	return (0);
}