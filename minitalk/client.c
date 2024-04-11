/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:51:00 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/11 16:25:44 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	ft_bits(char *str, char *bits)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (str[i])
// 	{
// 		j = 7;
// 		while (j >= 0)
// 		{
// 			bits[(i * 8) + (7 - j)] = ((str[i] >> j) & 1) + '0';
// 			j--;
// 		}
// 		i++;
// 	}
// 	bits[i * 8] = '\0';
// }

void	ft_send(pid_t server_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
		{
			kill(server_pid, SIGUSR1);
			exit(EXIT_SUCCESS);
		}
		else if (str[i] == '2')
		{
			kill(server_pid, SIGUSR2);
			exit(EXIT_SUCCESS);
		}
		else
		{
			ft_printf("invalid char");
			exit(EXIT_FAILURE);
		}
		usleep(500000);
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	char	*str;
	// char	bits[8 * ft_strlen(str) + 1];

	str = av[2];
	server_pid = ft_atoi(av[1]);
	if (ac == 3)
	{
		// ft_bits(str, bits);
		// ft_printf("%s\n", av[2]);
		// ft_printf("%s", bits);
		ft_send(server_pid, str);
	}
	else
		return (-1);
	return (0);
}
