/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:05:52 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/26 17:37:55 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*smallestnumber(t_list *stacka)
{
	t_list	*current;
	t_list	*smallest;

	current = stacka;
	smallest = stacka;
	while (current != NULL)
	{
		if (current->content < smallest->content)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

t_list	*biggestnumber(t_list *stacka)
{
	t_list	*current;
	t_list	*biggest;

	current = stacka;
	biggest = stacka;
	while (current != NULL)
	{
		if (current->content > biggest->content)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

void	target_check(t_list **stacka, t_list **stackb)
{
	t_list	*current_b;
	t_list	*current_a;
	t_list	*nearest_bigger;

	current_b = *stackb;
	while (current_b)
	{
		current_a = *stacka;
		nearest_bigger = NULL;
		while (current_a)
		{
			if (current_b->content > biggestnumber(*stacka)->content)
				nearest_bigger = smallestnumber(*stacka);
			else if (current_a->content > current_b->content)
			{
				if (!nearest_bigger || current_a->content
					< nearest_bigger->content)
					nearest_bigger = current_a;
			}
			current_a = current_a->next;
		}
		current_b->target = nearest_bigger;
		current_b = current_b->next;
	}
}

void	cheapest(t_list **stacka, t_list **stackb)
{
	t_list	*current_b;
	t_list	*current_a;

	current_b = *stackb;
	current_a = *stacka;
	while (current_b && current_b->target)
	{
		current_b->cheapest = current_b->target->cost + current_b->cost;
		current_b = current_b->next;
	}
}

t_list	*most_cheapest(t_list *stacka, t_list *stackb)
{
	t_list	*cheap;
	int		sum;

	cheapest(&stacka, &stackb);
	sum = stackb->cheapest;
	cheap = stackb;
	while (stackb)
	{
		if (stackb->cheapest < sum)
		{
			cheap = stackb;
			sum = cheap->cheapest;
		}
		stackb = stackb->next;
	}
	return (cheap);
}
