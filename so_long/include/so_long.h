/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:16 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/04 16:14:17 by jsamardz         ###   ########.fr       */
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

# define KEY_ESC 53
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

# define IMAGE_X 32
# define IMAGE_Y 32

// x je visina, y je duzina mape

typedef struct s_img
{
	void	*background;
	void	*player;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		collectible;
	void	*obj;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		exit_x;
	int		exit_y;
	int		player_x;
	int		player_y;
	int		moves;
	int		collected;
	t_map	*map;
	t_img	*img;
}	t_data;

// render_game
int		esc_game(t_data *data);

// load_img
void	background(t_data *data);
void	load_obj(t_data *data, char *path);
void	load_player(t_data *data);

// render_game
void	render_game(t_data *data);

// utils
void	free_array(char **s);
int		counter(char *str, char c);
int		close_win();
int		keypress(int keycode);

// map_path
void	map_path(t_data *data);

// input
int		ft_input(const char *name);

// map_size
void	map_size(t_data *data, char **av);

// error
void	ft_error(char *str);

// parse_map
void	parse_map(t_data *data, char **av);
void	rec_check(t_data *data);

#endif