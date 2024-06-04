/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:22 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/04 16:04:23 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(t_data *data, t_map *map)
{
	data->map = map;
	map->map = NULL;
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;

	if (ac != 2)
		ft_error("Error\nInvalid arguments");
	map_size(&data, av);
	init_map(&data, &map);
	data.map->map = (char **)malloc(sizeof(char *) * (data.map->y + 1));
	if (!data.map->map)
		ft_error("Error\nMemory allocation");
	parse_map(&data, av);
	map_path(&data);
	parse_map(&data, av);
	data.mlx = mlx_init();
	if (!data.mlx)
		ft_error("Error\nProgram init fail");
	data.win = mlx_new_window(data.mlx, IMAGE_X, IMAGE_Y, "./so_long");
	render_game(&data);
	mlx_hook(data.win, 2, 0, keypress, NULL);
	mlx_hook(data.win, 17, 0, close_win, NULL);
	mlx_loop(data.mlx);
	return (0);
}
