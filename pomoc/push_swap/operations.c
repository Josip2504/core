/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:11:07 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/27 08:53:58 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stacka)
{
	t_list	*current;
	t_list	*last;

	current = *stacka;
	last = NULL;
	if (*stacka == NULL || (*stacka)->next == NULL)
		return ;
	while (current->next != NULL)
	{
		last = current;
		current = current->next;
	}
	last->next = NULL;
	current->next = *stacka;
	*stacka = current;
	indexing(stacka);
}

void	pa(t_list **stacka, t_list **stackb)
{
	t_list	*node;

	node = *stackb;
	*stackb = (*stackb)->next;
	if (*stacka == NULL)
	{
		*stacka = node;
		node->next = NULL;
	}
	else
	{
		node->next = *stacka;
		*stacka = node;
	}
	indexing(stacka);
	indexing(stackb);
	median(stacka);
	median(stackb);
	cost(stackb);
	cost(stacka);
	write(1, "pa\n", 3);
}

void	pb(t_list **stacka, t_list **stackb)
{
	t_list	*node;

	node = *stacka;
	*stacka = (*stacka)->next;
	if (*stackb == NULL)
	{
		*stackb = node;
		node->next = NULL;
	}
	else
	{
		node->next = *stackb;
		*stackb = node;
	}
	indexing(stacka);
	indexing(stackb);
	median(stacka);
	median(stackb);
	cost(stackb);
	cost(stacka);
	write(1, "pb\n", 3);
}

void	rr(t_list **stacka, t_list **stackb)
{
	ra(stacka);
	rb(stackb);
	indexing(stacka);
	indexing(stackb);
	write(1, "rr\n", 3);
}

void	rrr(t_list **stacka, t_list **stackb)
{
	rra(stacka);
	rrb(stackb);
	indexing(stacka);
	indexing(stackb);
	write(1, "rrr\n", 4);
}
