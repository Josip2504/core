/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:16:29 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/19 11:16:29 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_char(char c)
{
	write (1, &c, 1);
}

void	ft_str(char *s)
{
	int i = 0;

	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
}

void ft_num(int i)
{
	if (i > 9)
	{
		ft_num(i / 10);
		ft_num(i % 10);
	}
	else
		ft_char(i + '0');
}

int main()
{
	int i = 0;
	while (i <= 100)
	{
		if ((i % 3 == 0) && (i % 5 == 0))
			ft_str("fizzbuzz");
		else if (i % 5 == 0)
			ft_str("buzz");
		else if (i % 3 == 0)
			ft_str("fizz");
		else
			ft_num(i);
		ft_char('\n');
		i++;
	}
	return (0);
}