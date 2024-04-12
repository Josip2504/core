/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:51:00 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/12 10:06:12 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(pid_t server_pid, char letter)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((letter & (0x01 << i)) == 0)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	char	*str;
	int		i;

	i = 0;
	str = av[2];
	server_pid = ft_atoi(av[1]);
	if (ac == 3)
	{
		while (*str)
		{
			ft_send(server_pid, *str);
			str++;
		}
		ft_send(server_pid, '\n');
	}
	else
		return (-1);
	return (0);
}
