/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:56:07 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/30 13:42:43 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int	is_surrounded_by_walls(t_map *map)
// {
// 	int	j;
// 	int i;

// 	j = 0;
// 	while (j < map->cols)
// 	{
// 		if (map->data[0][j] != '1' || map->data[map->rows - 1][j] != '1')
// 			return (0);
// 		j++;
// 	}
// 	i = 0;
// 	while (i < map->rows)
// 	{
// 		if (map->data[i][0] != '1' || map->data[i][map->cols - 1] != '1')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }
// void	init_visited(int visited[size][size], int rows, int cols)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < rows)
// 	{
// 		j = 0;
// 		while (j < cols)
// 		{
// 			visited[i][j] = 0;
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int	path_check(t_map *map, int visited[size][size])
// {
// 	int	dir[4][2];
// 	int	queue[size * size][2];
// 	int	front;
// 	int	rear;

// 	dir[0][0] = -1; dir[0][1] = 0;
// 	dir[1][0] = 1; dir[1][1] = 0;
// 	dir[2][0] = 0; dir[2][1] = -1;
// 	dir[3][0] = 0; dir[3][1] = -1;
// }

// int	is_valid_path(t_map *map)
// {
// 	int visited[size][size];
// 	int res;

// 	init_visited(visited, map->rows, map->cols);
// 	res = path_check(map, visited);
// 	return (res);
// }
