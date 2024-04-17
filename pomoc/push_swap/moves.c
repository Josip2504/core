/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:04:40 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/27 08:48:11 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacksorted(t_list **stacka)
{
	t_list	*current;

	current = *stacka;
	while (current != NULL && current->next != NULL)
	{
		if (current->content > current->next->content)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ra_p(t_list **stacka)
{
	ra(stacka);
	write(1, "ra\n", 3);
}

void	rb_p(t_list **stackb)
{
	rb(stackb);
	write(1, "rb\n", 3);
}

void	rra_p(t_list **stacka)
{
	rra(stacka);
	write(1, "rra\n", 4);
}

void	rrb_p(t_list **stackb)
{
	rrb(stackb);
	write(1, "rrb\n", 4);
}
