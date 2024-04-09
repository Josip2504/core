/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:19:16 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/09 13:41:53 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minitalk.h"
#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t server_pid;

	server_pid = getpid();
	printf("Server PID: %d\n", server_pid);
	return (0);
}
