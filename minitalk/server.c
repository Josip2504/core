/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:51:11 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/12 10:36:34 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	static int	str;
	static int	bitcount;

	if (signum == SIGUSR2)
		str |= (0x01 << bitcount);
	bitcount++;
	if (bitcount == 8)
	{
		if (str == '\n')
			ft_printf("end\n");
		else
			ft_printf("message: %c\n", str);
		str = 0;
		bitcount = 0;
	}
}

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
