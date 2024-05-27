/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:50:03 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/27 14:34:09 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    leaks(void)
{
    system("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_stack;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	stack_a = fill_stack(ac, av);
	size_stack = stack_size(stack_a);
	stack_id(stack_a, size_stack + 1);
	push_swap(&stack_a, &stack_b, size_stack);
	free_stack(&stack_a);
	free_stack(&stack_b);
	atexit(leaks);
	return (0);
}
