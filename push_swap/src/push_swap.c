/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:32:45 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/16 16:29:14 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_biggest(t_stack *stack)
{
	int	biggest;

	biggest = stack->index;
	while (stack)
	{
		if (stack->index > biggest)
			biggest = stack->index;
		stack = stack->next;
	}
	return (biggest);
}

void	sort_three(t_stack **stack)
{
	int	biggest;

	biggest = find_biggest(*stack);
	if (!is_sorted(*stack))
	{
		if ((*stack)->index == biggest)
			ft_ra(stack);
		else if ((*stack)->next->index == biggest)
			ft_rra(stack);
		if ((*stack)->index > (*stack)->next->index)
			ft_sa(stack);
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (!is_sorted(*stack_a) && size == 2)
		ft_rra(stack_a);
	else if (!is_sorted(*stack_a) && size == 3)
		sort_three(stack_a);
	else if (!is_sorted(*stack_a) && size > 3)
		ft_algorithm(stack_a, stack_b);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
