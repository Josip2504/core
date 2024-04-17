/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:08:55 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/26 18:25:22 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_error2(char **s)
{
	int	i;

	i = 1;
	while (s[i])
	{
		if (ft_isdigits_str(s[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isduplicate(t_list *stack)
{
	int		i;
	t_list	*tmp;
	t_list	*new;
	int		num;

	i = 0;
	new = stack;
	while (new)
	{
		tmp = new;
		num = new->content;
		i = 0;
		while (tmp)
		{
			if (tmp->content == num)
				i++;
			if (i > 1)
			{
				return (1);
			}
			tmp = tmp->next;
		}
		new = new->next;
	}
	return (0);
}

int	ft_check_error1(char **s)
{
	int		i;
	long	num;
	long	min;
	long	max;

	min = -2147483648;
	max = 2147483647;
	i = 1;
	while (s[i])
	{
		num = ft_atol(s[i]);
		if (num < min || num > max)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigits_str(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL || *str == '\0')
		return (1);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	if (!ft_isdigit(str[i]))
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '\t'
			&& str[i] == '\0')
			return (1);
		else if (ft_isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}
