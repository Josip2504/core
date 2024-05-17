/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:37:09 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/17 12:59:17 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_low_pos(t_stack **stack)
{
	int		low_id;
	int		low_pos;
	t_stack	*temp;

	low_id = INT_MAX;
	temp = *stack;
	get_pos(stack);
	low_pos = temp->pos;
	while (temp)
	{
		if (temp->index < low_id)
		{
			low_id = temp->index;
			low_pos = temp->pos;
		}
		temp = temp->next;
	}
	return (low_pos);
}

static void	push_unitl_three(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;
	int	i;

	i = 0;
	size = stack_size(*stack_a);
	pushed = 0;
	while (size > 6 && i++ < size && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			ft_pb(stack_a, stack_b);
			pushed++;
		}
		else
			ft_ra(stack_a);
	}
	while (size - pushed > 3)
	{
		ft_pb(stack_a, stack_b);
		pushed++;
	}
}

static void	ft_shift(t_stack **stack_a)
{
	int	size;
	int	low_pos;

	size = stack_size(*stack_a);
	low_pos = ft_low_pos(stack_a);
	if (low_pos > size / 2)
	{
		while (low_pos < size)
		{
			ft_rra(stack_a);
			low_pos++;
		}
	}
	else
	{
		while (low_pos > 0)
		{
			ft_ra(stack_a);
			low_pos--;
		}
	}
}

void	ft_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	push_unitl_three(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_pos(stack_a, stack_b);
		cost(stack_a, stack_b);
		cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		ft_shift(stack_a);
}
