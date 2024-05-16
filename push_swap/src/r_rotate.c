/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:42:56 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/10 13:13:31 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_r_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*bot;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = *stack;
		bot = NULL;
		while (temp->next != NULL)
		{
			bot = temp;
			temp = temp->next;
		}
		temp->next = *stack;
		*stack = temp;
		bot->next = NULL;
	}
}

void	ft_rra(t_stack **stack_a)
{
	ft_r_rotate(stack_a);
	ft_printf("rra\n");
}

void	ft_rrb(t_stack **stack_b)
{
	ft_r_rotate(stack_b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_r_rotate(stack_a);
	ft_r_rotate(stack_b);
	ft_printf("rrr\n");
}
