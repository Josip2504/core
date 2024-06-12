/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:18:29 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/12 15:14:58 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_er(char *str)
{
	perror(str);
	exit(1);
}
void	exicute_ls(char **av)
{
	if (execve("/bin/ls", av, NULL) == -1)
		ft_er("fork() error");
}

void	exicute_cat(char **av)
{
	if (execve("/bin/cat", av, NULL) == -1)
		ft_er("fork() error");
}

//replace strtok with lexer tokens

void	exicute_external(char *input)
{
	pid_t	pid;
	char	*av[1024];
	int		i;
	int		status;

	i = 0;
	av[i++] = strtok(input, " ");
	while (1)
	{
		av[i++] = strtok(NULL, " ");
		if (av[i] == NULL)
			break ;
	}
	pid = fork();
	if (pid < 0)
		ft_er("fork() error");
	else if (pid == 0)
	{
		if (strcmp(av[0], "ls") == 0)
			exicute_ls(av);
		else if (strcmp(av[0], "cat") == 0)
			exicute_cat(av);
	}
	else
		waitpid(pid, &status, 0);
}
