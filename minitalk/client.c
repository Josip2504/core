/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:19:14 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/09 15:51:28 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	pid_t	server_pid;
	char	*str;
	str = av[2];
	server_pid = ft_atoi(av[1]);
	if (ac == 3)
	{
		
	}
	else
		return (-1);
	return (0);
}
