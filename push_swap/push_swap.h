/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:46:45 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/07 12:44:05 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				pos_target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// input
void	ft_input(int ac, char **av);

// handling
void	ft_free(char **str);
void	ft_error(char *str);
void	free_stack(t_stack **stack);
void	stack_id(t_stack *stack_a, int stack_size);

// stacks
t_stack	*get_bottom(t_stack *stack);
t_stack	*new_stack(int value);
void	add_to_bottom(t_stack *new, t_stack **stack);
int		stack_size(t_stack *stack);
t_stack	*fill_stack(int ac, char **av);

// push_swap
void	push_swap(t_stack **stack_a, t_stack **stack_b, int size);
int		is_sorted(t_stack *stack);

// rotate
void	ft_rotate(t_stack **stack);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);

#endif