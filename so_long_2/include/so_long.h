/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:16 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/30 14:12:39 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <stdio.h>
# include <string.h>

# define MAX_MAP_SIZE 100

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
}	t_data;

// maps
typedef struct s_map
{
	char	**data;
	int		rows;
	int		cols;
	int		player_row;
	int		player_col;
	int		exit_row;
	int		exit_col;
	int		num_collectibles;
}	t_map;

char	*parse_map(const char *filename, t_map	*map);
void	free_map(t_map *map);
void	init_map(t_map *map, int rows, int cols);

#endif