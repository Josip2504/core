/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:51:11 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/11 16:10:12 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("receved s1\n");
	else if (signum == SIGUSR2)
		ft_printf("receved s2\n");
}

int	main(void)
{
	pid_t server_pid;

	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		sleep(1);
	return (0);
}
