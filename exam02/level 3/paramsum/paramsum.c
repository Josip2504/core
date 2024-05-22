/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:57:13 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/21 13:08:51 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_n(int n)
{
	char i;

	if (n >= 10)
		ft_n(n / 10);
	i = (n % 10) + '0';
	write (1, &i, 1);
}

int main (int ac, char **av)
{
	int i = 0;
	while (i < ac - 1)
		i++;
	ft_n(i);
	write (1, "\n", 1);
	return (0);
}