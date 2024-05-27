/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:25:08 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/22 12:38:28 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int n = nbr;
	int len = 0;
	char *res;

	if (nbr == -2147483648)
		return("-2147483648\0");
	if (nbr <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nbr == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		res[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (res);
}