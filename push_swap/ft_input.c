/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:44:52 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/06 11:43:06 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checking is number

int	ft_num(char *s)
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

int	ft_duplicate(int i, char **res, int temp)
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

void	ft_input(int ac, char **av)
{
	char	**res;
	int		i;
	int		temp;

	i = 0;
	if (ac == 2)
		res = ft_split(av[1], 32);
	else
	{
		i = 1;
		res = av;
	}
	while (res[i])
	{
		temp = ft_atoi(res[i]);
		if (!ft_num(res[i]))
			ft_error("Error\n");
		else if (ft_duplicate(i, res, temp))
			ft_error("Error\n");
		else if (temp > INT_MAX || temp < INT_MIN)
			ft_error("Error\n");
		i++;
	}
}
