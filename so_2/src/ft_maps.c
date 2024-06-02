/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                           s         +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:16:37 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/01 17:48:22 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	parse_map(char *file, t_data *data)
{

}

int	read_map(t_data *data, char *file)
{
	int	check;

	get_row_num(data, file);
	printf("%d\n", data->map->rows);
	printf("%d\n", data->map->cols);
	// parse_map(file, data);			//create new parse map
	// check = check_map(data);
	// if (check > 0)
	// 	ft_error("Error\nInvalid map");
	return (0);
}
