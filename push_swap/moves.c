/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:10:15 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/13 15:58:33 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a(t_stack **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_ra(stack_a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_rra(stack_a);
			(*cost)++;
		}
	}
}

static void	rotate_b(t_stack **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_rb(stack_b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_rrb(stack_b);
			(*cost)++;
		}
	}
}

static void	rotate_both(t_stack **stack_a, t_stack **stack_b, int *a_cost, int *b_cost)
{
	while (*a_cost > 0 && *b_cost > 0)
	{
		(*a_cost)--;
		(*b_cost)--;
		ft_rr(stack_a, stack_b);
	}
}

static void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b, int *a_cost, int *b_cost)
{
	while (*a_cost < 0 && *b_cost < 0)
	{
		(*a_cost)++;
		(*b_cost)++;
		ft_rrr(stack_a, stack_b);
	}
}

void	ft_move(t_stack **stack_a, t_stack **stack_b, int a_cost, int b_cost)
{
	if (a_cost < 0 && b_cost < 0)
		rev_rotate_both(stack_a, stack_b, &a_cost, &b_cost);
	if (a_cost > 0 && b_cost > 0)
		rotate_both(stack_a, stack_b, &a_cost, &b_cost);
	rotate_a(stack_a, &a_cost);
	rotate_b(stack_b, &b_cost);			// cost
	ft_pa(stack_a, stack_b);
}
