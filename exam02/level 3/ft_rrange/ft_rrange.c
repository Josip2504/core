/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:16:34 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/22 12:24:21 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int *range;
	int step = 1;
	int i = 0;
	int n = end - start;

	if (n < 0)
		n *= -1;
	n++;
	range = malloc(sizeof(int) * n);
	if (range)
	{
		if (start - end)
			step = -1;
		while (i < n)
		{
			range[i] = end;
			end = end + step;
			i++;
		}
	}
	return (range);
}