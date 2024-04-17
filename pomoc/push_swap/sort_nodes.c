/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:06:46 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/26 18:35:10 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorthree(t_list **stacka)
{
	t_list	*big;

	big = biggestnumber(*stacka);
	if (*stacka == big)
		ra_p(stacka);
	else if ((*stacka)->next == big)
		rra_p(stacka);
	if ((*stacka)->content > (*stacka)->next->content)
		sa_r(stacka);
}

void	sortwo(t_list **stacka)
{
	t_list	*big;

	big = biggestnumber(*stacka);
	if (*stacka == big)
		ra_p(stacka);
}

void	easy_move_b(t_list **stackb, t_list *small)
{
	if (small->above_median)
		while (*stackb != small)
			rb_p(stackb);
	else
		while (*stackb != small)
			rrb_p(stackb);
}

void	easy_move_a(t_list **stacka, t_list *node)
{
	if (node->above_median)
		while (*stacka != node)
			ra_p(stacka);
	else
		while (*stacka != node)
			rra_p(stacka);
}

void	move_nodes(t_list **stacka, t_list **stackb)
{
	t_list	*cheap;

	cheap = most_cheapest(*stacka, *stackb);
	if (cheap->above_median && cheap->target->above_median)
	{
		while (cheap != *stackb && cheap->target != *stacka)
			rr(stacka, stackb);
	}
	else if (!(cheap->above_median) && !(cheap->target->above_median))
	{
		while (cheap != *stackb && cheap->target != *stacka)
			rrr(stacka, stackb);
	}
	easy_move_a(stacka, cheap->target);
	easy_move_b(stackb, cheap);
	indexing(stacka);
	indexing(stackb);
	pa(stacka, stackb);
}
