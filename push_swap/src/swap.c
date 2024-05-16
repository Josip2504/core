/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:44:48 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/16 16:26:11 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{	
	int		temp;

	if (stack != NULL || stack->next != NULL)
	{
		temp = stack->value;
		stack->value = stack->next->value;
		stack->next->value = temp;
		temp = stack->index;
		stack->index = stack->next->index;
		stack->next->index = temp;
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
