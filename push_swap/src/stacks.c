/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:54:27 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/17 13:08:09 by jsamardz         ###   ########.fr       */
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

t_stack	*new_stack(int value)
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

static void	add_to_bottom(t_stack *new, t_stack **stack)
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

//filling stack

t_stack	*fill_stack(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;
	int		num;
	char	**numbers;

	num = 0;
	i = 0;
	if (ac == 2)
		numbers = ft_split(av[1], 32);
	else
	{
		numbers = av;
		i = 1;
	}
	while (numbers[i])
	{
		num = ft_atoi(numbers[i]);
		ft_input(numbers, num, i);
		if (stack_a == NULL)
			stack_a = new_stack(num);
		else
			add_to_bottom(new_stack(num), &stack_a);
		i++;
	}
	return (stack_a);
}
