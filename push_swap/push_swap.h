/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:46:45 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/06 15:30:24 by jsamardz         ###   ########.fr       */
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

void	ft_input(int ac, char **av);
int		ft_duplicate(int i, char **res, int temp);
void	ft_free(char **str);
void	ft_error(char *str);
int		stack_size(t_stack *stack);
t_stack	*fill_stack(int ac, char **av);
void	add_to_bottom(t_stack *new, t_stack **stack);
t_stack	*new_stack (int value);
t_stack	*get_bottom(t_stack *stack);
void	stack_id(t_stack *stack_a, int stack_size);
void	free_stack(t_stack **stack);

#endif