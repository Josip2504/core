/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:16:37 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/30 14:16:15 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(t_map *map, int rows, int cols)
{
	int i;
	
	map->rows = rows;
	map->cols = cols;

	map->data = (char**)malloc(rows * sizeof(char*));
	if (!map->data)
	{
		free_map(map);
		exit(1);
	}
	i = 0;
	while (i < rows)
	{
		map->data[i] = (char*)malloc(cols * sizeof(char));
		if (!map->data[i])
		{
			free_map(map);
			exit(1);
		}
		i++;
	}
}

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->rows)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
}

char	*parse_map(const char* filename, t_map *map)
{
	FILE*	file;
	char	line[1024];
	int		len;
	int		j;
	char	ch;

	file = fopen(filename, "r");
	if (!file)
		return ("Error: Failed to open file.");
	map->rows = 0;
	map->cols = 0;
	map->player_row = -1;
	map->player_col = -1;
	map->exit_row = -1;
	map->exit_col = -1;
	map->num_collectibles = 0;
	init_map(map, map->rows, map->cols);
	fclose(file);
	return ("map parsed");
}
