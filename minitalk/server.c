/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:51:11 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/12 11:46:30 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	static char	receved_char;
	static char	bit_count;
	if (signum == SIGUSR1)
		receved_char |= (0 << bit_count);
	else if (signum == SIGUSR2)
		receved_char |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		if (receved_char == '\0')
		{
			ft_printf("\n");
			return ;
		}
		ft_printf("%c", receved_char);
		receved_char = 0;
		bit_count = 0;
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
