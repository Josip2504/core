/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:50:03 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/30 13:19:19 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(int ac, char **av)
// {
// 	t_stack *stack_a;
// 	t_stack *stack_b;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	if (ac < 2)
// 		return (-1);
// 	ft_input(ac, av);
// }

int main(int argc, char **argv) {
    if (argc < 2) {
        ft_printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    ft_input(argc, argv);
    return 0;
}