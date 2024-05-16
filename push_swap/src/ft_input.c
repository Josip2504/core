/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:44:52 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/16 13:58:18 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checking is number

static int	ft_num(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

// checking for duplicates

static int	ft_duplicate(int i, char **res, int temp)
{
	i++;
	while (res[i])
	{
		if (ft_atoi(res[i]) == temp)
			return (1);
		i++;
	}
	return (0);
}

// checking is input correct and making it correct

void	ft_input(char **numbers, int num, int i)
{
	num = ft_atoi(numbers[i]);
	if (!ft_num(numbers[i]))
		ft_error("Error\n");
	else if (ft_duplicate(i, numbers, num))
		ft_error("Error\n");
	else if (num > INT_MAX || num < INT_MIN)
		ft_error("Error\n");
}
