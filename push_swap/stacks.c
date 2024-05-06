/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:54:27 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/06 14:24:17 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//get stack bottom

t_stack	*get_bottom(t_stack *stack)
{
	while (stack->next != NULL && stack)
		stack = stack->next;
	return (stack);
}

//creates stack with value

t_stack	*new_stack (int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->pos_target = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

//adds element to stack bottom

void	add_to_bottom(t_stack *new, t_stack **stack)
{
	t_stack	*bot;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	bot = get_bottom(*stack);
	bot->next = new;
}

//get stack size

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}