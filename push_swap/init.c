/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:47:02 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/06 15:13:26 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//filling stack

t_stack	*fill_stack(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;
	int		num;

	num = 0;
	i = 1;
	stack_a = NULL;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if (i == 1)
			stack_a = new_stack(num);
		else
			add_to_bottom(new_stack(num), &stack_a);
		i++;
	}
	return (stack_a);
}

// give id to every value inside a stack

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
