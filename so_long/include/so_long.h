/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:16 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/02 15:33:00 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# define IMAGE_X 32
# define IMAGE_Y 32

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		collectible;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	t_map	*map;
}	t_data;

// input
int		ft_input(const char *name);

// map_size
void	map_size(t_data *data, char **av);

// error
void	ft_error(char *str);

#endif