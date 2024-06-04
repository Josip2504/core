/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:27:40 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/05 00:47:15 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_map_player(t_data *data)
{
	char	*path;
	int		img_w;
	int		img_h;

	path = "./img/player.xpm";
	data->img->player = mlx_xpm_file_to_image(data->mlx, path,
		&img_w, &img_h);
}

void	init_map(t_data *data, t_map *map)
{
	t_img	*img;
	char	*path;
	int		img_w;
	int		img_h;
	
	data->map = map;
	data->map->obj = NULL;
	img = malloc(sizeof(t_img));
	if (!img)
		ft_error("Error\nMemory alloc");
	data->img = img;
	data->collected = 0;
	data->moves = 0;
	path = "./img/background.xpm";
	data->img->background = mlx_xpm_file_to_image(data->mlx, path,
		&img_w, &img_h);
	init_map_player(data);
}
