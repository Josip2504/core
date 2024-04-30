/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:44:52 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/30 13:40:24 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (ft_num(res[i]))
			ft_printf("Error\n");
		if (ft_duplicate(i, res, temp))
			ft_printf("Error\n");
		i++;
	}
	if (ac == 2)
		ft_free(res);
}
