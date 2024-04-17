/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:05:13 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/17 16:11:33 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int     *ft_range(int start, int end)
{
	int i = 0;
	int size;
	int *tab;

	size = ft_value(start - end);
	tab = (int *)malloc(sizeof(int) * size + 1);
	if (!tab)
		return (0);
	while (start < end)
	{
		tab[i] = start;
		start++;
		i++;
	}
	tab[i] = start;
	while (start > end)
	{
		tab[i] = start;
		start--;
		i++;
	}
	tab[i] = start;
	return (tab);
}