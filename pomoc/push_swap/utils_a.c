/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:10:36 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/26 18:34:23 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	z;
	int	neg_counter;

	i = 0;
	z = 0;
	neg_counter = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg_counter++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		z = z * 10 + (str[i] - '0');
		i++;
	}
	if (neg_counter == 1)
		z *= -1;
	return (z);
}

int	ft_isdigits(int c)
{
	return ((c >= '0' && c <= '9') || c == '-');
}

long	ft_atol(const char *str)
{
	long	i;
	long	z;
	long	neg_counter;

	i = 0;
	z = 0;
	neg_counter = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' )
			neg_counter++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		z = z * 10 + (str[i] - '0');
		i++;
	}
	if (neg_counter == 1)
	{
		z *= -1;
	}
	return (z);
}

void	ft_checkdouble(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && str[i + 1] == '-')
			ft_error();
		if (str[i + 1] == '-')
			ft_error();
		i++;
	}
}
