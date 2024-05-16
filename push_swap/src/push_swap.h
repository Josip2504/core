/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:46:45 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/16 14:33:48 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
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
void	ft_input(char **numbers, int num, int i);

// handling
void	ft_free(char **str);
void	ft_error(char *str);
void	free_stack(t_stack **stack);
void	stack_id(t_stack *stack_a, int stack_size);
int		ft_abs (int n);

// stacks
t_stack	*get_bottom(t_stack *stack);
t_stack	*new_stack(int value);
void	add_to_bottom(t_stack *new, t_stack **stack);
int		stack_size(t_stack *stack);
t_stack	*fill_stack(int ac, char **av);

// push_swap
void	push_swap(t_stack **stack_a, t_stack **stack_b, int size);
int		is_sorted(t_stack *stack);
void	sort_three(t_stack **stack);

// rotate
void	ft_rotate(t_stack **stack);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);

// swap
void	ft_swap(t_stack *stack);
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);

// push
void	ft_push(t_stack **src, t_stack **dest);
void	ft_pa(t_stack **stack_b, t_stack **stack_a);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);

// reverse rotate
void	ft_r_rotate(t_stack **stack);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

// algorithm
void	ft_algorithm(t_stack **stack_a, t_stack **stack_b);

// target
void	get_target_pos(t_stack **stack_a, t_stack **stack_b);
void	get_pos(t_stack **stack);

// cost
void	cost(t_stack **stack_a, t_stack **stack_b);
void	cheapest_move(t_stack **stack_a, t_stack **stack_b);

// move
void	ft_move(t_stack **stack_a, t_stack **stack_b, int a_cost, int b_cost);

#endif
