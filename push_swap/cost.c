/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:52:02 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/10 13:13:17 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// finding cheapest element in stack_b and moving it to stack_a

void	cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		a_cost;
	int		b_cost;
	int		cheapest;

	cheapest = INT_MAX;
	temp = *stack_b;
	while (temp)
	{
		if (ft_abs(temp->cost_a) + ft_abs(temp->cost_b) < ft_abs(cheapest))
		{
			cheapest = ft_abs(temp->cost_b) + ft_abs(temp->cost_a);
			a_cost = temp->cost_a;
			b_cost = temp->cost_b;
		}
		temp = temp->next;
	}
	ft_move(stack_a, stack_b, a_cost, b_cost);
}

// calcucating cost of moving elements from stack_b to correct pos in stack_a

void	cost(t_stack **stack_a, t_stack **stack_b)
{
	int		a_size;
	int		b_size;
	t_stack	*a;
	t_stack	*b;

	a = *stack_a;
	b = *stack_b;
	a_size = stack_size(a);
	b_size = stack_size(b);
	while (b)
	{
		b->cost_b = b->pos;
		if (b->pos > b_size / 2)
			b->cost_b = (b_size - b->pos) * -1;
		b->cost_a = b->pos_target;
		if (b->pos_target > a_size / 2)
			b->cost_a = (a_size - b->pos_target) * -1;
		b = b->next;
	}
}
