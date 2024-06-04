/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:59:31 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/04 16:15:14 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_map(t_data *data)
{
	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < (data->y / IMAGE_X))
	{
		if (data->map->map[data->map->y][data->map->x] == 'P')
			load_player(data);
		else if (data->map->map[data->map->y][data->map->x] == 'E')
			load_obj(data, "../img/exit.png");
		else if (data->map->map[data->map->y][data->map->x] == '1')
			load_obj(data, "../img/wall.png");
		else if (data->map->map[data->map->y][data->map->x] == 'C')
			load_obj(data, "../img/col.png");
		if (data->map->x < (data->x / IMAGE_Y))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}

int key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		esc_game(data);
	else if (keycode == 53)
		moves(data, 'y', UP);
	else if (keycode == 53)
		moves(data, 'x', LEFT);
	else if (keycode == 53)
		moves(data, 'y', DOWN);
	else if (keycode == 53)
		moves(data, 'x', RIGHT);
	if (data->map->map[data->player_y][data->player_x] == 'E')
		game_over(data);
	return (0);
}

int	esc_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("You exit game");
	exit(EXIT_SUCCESS);
}

void	render_game(t_data *data)
{
	background(data);
	load_map(data);
	mlx_hook(data->win, 17, 1L << 2, esc_game, data);
	mlx_key_hook(data->win, key_hook, data);
}
