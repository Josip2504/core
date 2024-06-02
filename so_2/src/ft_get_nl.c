/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:39:41 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/02 13:16:33 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nOpening file");
	return (fd);
}

int	get_nl(int fd)
{
	int		i;
	int		p;
	char	c;
	ssize_t	b_read;

	i = 1;
	p = '\0';
	if (read(fd, &c, 1) > 0 && c != '1')
		ft_error("Error\nInvalid map");
	b_read = read(fd, &c, 1);
	while (b_read > 0)
	{
		b_read = read(fd, &c, 1);
		if (c == '\n')
		{
			if (p == '\n')
				ft_error("Error\nInvalid map");
			i++;
		}
		p = c;
	}
	if (p != '1')
		ft_error("Error\nInvalid map");
	return (i);
}

void	count_cols(int fd, int *cols)
{
	int		cc;
	int		cur_cc;
	char	cur_char;
	int		fl;
	ssize_t	br;

	cc = 0;
	cur_cc = 0;
	fl = 1;
	br = read(fd, &cur_char, 1);
	while (br > 0)
	{
		br = read(fd, &cur_char, 1);
		if (cur_char == '\n')
		{
			if (fl)
			{
				cc = cur_cc;
				fl = 0;
			}
			else if (cur_cc != cc)
				ft_error("Error\nInvalid map");
			cur_cc = 0;
		}
		else
			cur_cc++;
	}
	if (cur_cc > 0)
	{
		if (fl)
			cc = cur_cc;
		else if (cur_cc != cc)
			ft_error("Error\nInvalid map");
	}
	if (br < 0)
		ft_error("Error\nRead error");
	*cols = cc;
}

int	get_cols(char *file)
{
	int	fd;
	int	cols;

	fd = open_file(file);
	count_cols(fd, &cols);
	if (close(fd) < 0)
		ft_error("Error\nClosing file");
	return (cols);
}

void	get_row_num(t_data *data, char *file)
{
	int	fd;
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nOpenning file");
	rows = get_nl(fd);
	data->map->rows = rows;
	// cols = get_cols(file);
	// data->map->cols = cols;
	close(fd);
}
