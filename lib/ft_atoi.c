/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:58:24 by jsamardz          #+#    #+#             */
/*   Updated: 2024/03/10 14:24:57 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	checker(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = n * 10 + (str[i] - '0');
		i ++;
	}
	return (n);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	m;
	int	num;

	i = 0;
	m = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
	{
		m = 1;
		i++;
	}
	if (str[i] == '-')
	{
		m = -1;
		i++;
	}
	num = checker((char *)&str[i]);
	return (num * m);
}
