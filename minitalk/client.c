/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:51:00 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/12 12:51:13 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// sigusr1 is sendin 0
// sigusr2 is sendin 1

void	ft_send(pid_t server_pid, char letter)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((letter & (0x01 << i)) == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	char	*str;

	str = av[2];
	server_pid = ft_atoi(av[1]);
	if (ac != 3)
		return (-1);
	while (*str)
	{
		ft_send(server_pid, *str);
		str++;
	}
	ft_send(server_pid, '\0');
	return (0);
}
