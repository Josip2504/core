/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:47:02 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/06 14:24:23 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//filling stack

t_stack	*fill_stack(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;
	int		num;

	num = 0;
	i = 1;
	stack_a = NULL;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if (i == 1)
			stack_a = new_stack(num);
		else
			add_to_bottom(new_stack(num), &stack_a);
		i++;
	}
	return (stack_a);
}