/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:46:45 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/03 13:06:17 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

int		ft_input(int ac, char **av);
int		ft_duplicate(int i, char **res, int temp);
void	ft_free(char **str);
void	ft_error(char *str);

#endif