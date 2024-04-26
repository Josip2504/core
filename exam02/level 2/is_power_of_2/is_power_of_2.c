/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:12:47 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/26 09:12:47 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n != 1);
	{
		if (n % 2 == 0)
			return (0);
		n /= 2;
	}
	return (1);
}

int main (void)
{
	unsigned int n = 2;
	
	if (is_power_of_2(n) == 1)
		printf("is power");
	else
		printf("is not");
	return (0);
}