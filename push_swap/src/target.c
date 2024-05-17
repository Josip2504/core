/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:29:58 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/17 12:52:37 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// picking best target in stack_a for next element in stack_b

static int	get_target(t_stack **stack_a, int b_id,
		int target_pos, int target_id)
{
	t_stack	*a;

	a = *stack_a;
	while (a)
	{
		if (a->index > b_id && a->index < target_id)
		{
			target_id = a->index;
			target_pos = a->pos;
		}
		a = a->next;
	}
	if (target_id != INT_MAX)
		return (target_pos);
	a = *stack_a;
	while (a)
	{
		if (a->index < target_id)
		{
			target_id = a->index;
			target_pos = a->pos;
		}
		a = a->next;
	}
	return (target_pos);
}

// assiging postiont to elements from top to bottom

void	get_pos(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

// assisgning target pos for every element in stack_a

void	get_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	int		target_pos;
	t_stack	*b;

	b = *stack_b;
	get_pos(stack_a);
	get_pos(stack_b);
	target_pos = 0;
	while (b)
	{
		target_pos = get_target(stack_a, b->index, target_pos, INT_MAX);
		b->pos_target = target_pos;
		b = b->next;
	}
}
