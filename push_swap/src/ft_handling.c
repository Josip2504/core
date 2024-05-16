/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:34:08 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/10 13:13:21 by jsamardz         ###   ########.fr       */
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
// give id to every value inside stack accordigly to value

void	stack_id(t_stack *stack_a, int stack_size)
{
	t_stack	*tab;
	t_stack	*top;
	int		value;

	while (--stack_size > 0)
	{
		top = NULL;
		tab = stack_a;
		value = INT_MIN;
		while (tab)
		{
			if (tab->index == 0 && tab->value == INT_MIN)
				tab->index = 1;
			if (tab->index == 0 && tab->value > value)
			{
				value = tab->value;
				top = tab;
				tab = stack_a;
			}
			else
				tab = tab->next;
		}
		if (top != NULL)
			top->index = stack_size;
	}
}

int	ft_abs (int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
