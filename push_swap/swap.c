/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:44:48 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/08 12:06:38 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_stack	*first;
	t_stack	*second;
	int		temp;

	if (stack != NULL && stack->next != NULL)
	{
		first = stack;
		second = stack->next;
		temp = first->value;
		first->value = second->value;
		second->value = temp;
	}
}

void	ft_sa(t_stack **stack_a)
{
	ft_swap(*stack_a);
	ft_printf("sa\n");
}

void	ft_sb(t_stack **stack_b)
{
	ft_swap(*stack_b);
	ft_printf("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(*stack_a);
	ft_swap(*stack_b);
	ft_printf("ss\n");
}
