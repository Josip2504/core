/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_sa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:45:52 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/27 08:48:00 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_r(t_list **stacka)
{
	sa(stacka);
	write(1, "sa\n", 3);
}

void	sb_r(t_list **stackb)
{
	sb(stackb);
	write(1, "sb\n", 3);
}

void	ss(t_list **stacka, t_list **stackb)
{
	sa(stacka);
	sb(stackb);
	write(1, "ss\n", 3);
}
