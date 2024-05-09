/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:37:09 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/09 13:32:53 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_shift(t_stack **stack_a)
{
	
}

static void	push_unitl_three(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;

	size = stack_size(*stack_a);
	pushed = 0;
	while (size > 3)
	{
		if ((*stack_a)->index <= size / 2)
		{
			ft_pb(stack_a, stack_b);
			pushed++;
		}
		else
			ft_ra(stack_a);
		size = stack_size(*stack_a);
	}
	while (pushed < size)
	{
		ft_pb(stack_a, stack_b);
		pushed++;
	}
}

void	ft_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	push_unitl_three(stack_a, stack_b);
	sort_three(stack_a);
	while(*stack_b)
	{
		get_target_pos(stack_a, stack_b);
		cost(stack_a, stack_b);
		ft_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		ft_shift(stack_a);
}
