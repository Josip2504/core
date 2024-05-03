/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:50:03 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/03 13:10:33 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *stack, int num)
{
	stack->value = num;
	printf("%d\n", stack->value);
}

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int		num;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (-1);
	num = ft_input(ac, av);
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	ft_push(stack_a, num);
	// check is sorted, if is -> free stacks
	// sort stacks
	// free stacks
	return (0);
}
