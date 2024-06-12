/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:18:29 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/12 14:23:38 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exicute_external(char *input)
{
	pid_t	pid;
	char	*av[1024];
	int 	i;
	int		status;

	i = 0;
	av[i++] = strtok(input, " ");
	while ((av[i] = strtok(NULL, " ")) != NULL)
		i++;
	pid = fork();
	if (pid < 0)
	{
		perror("fork() error");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execvp(av[0], av) == -1)
		{
			perror("fork() error");
			exit(1);
		}
	}
	else
		waitpid(pid, &status, 0);
}
