/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:22 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/30 14:12:43 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#define KEY_ESC 53

int	ft_error(char *str)
{
	ft_printf("%s\n", str);
	return (0);
}

int close_win()
{
	exit (0);
}

int keypress(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (ft_error("Invalid arguments"));
	
	// result = parse_map(filename, &map);
	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Game");
	// mlx_hook(win_ptr, 2, 0, keypress, NULL);
	// mlx_hook(win_ptr, 17, 0, close_win, NULL);
	// mlx_loop(mlx_ptr);
	return 0;
}
