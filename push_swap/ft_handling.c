/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:34:08 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/06 15:30:14 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

void	ft_error(char *str)
{
	ft_printf("%s", str);
	exit(0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*s;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		s = (*stack)->next;
		free(*stack);
		*stack = s;
	}
	*stack = NULL;
}
