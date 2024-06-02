/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:22 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/02 16:31:58 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int	main(int ac, char **av)
// {
// 	t_data	data;
// 	t_map	map;

// 	if (ac != 2)
// 		ft_error("Error\nInvalid arguments");
// 	map_size(&data, av);
// 	return (0);
// }

int main(void)
{
    int fd;
    char *line;

    // Open a file for reading
    fd = open("map.ber", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read lines until the end of file is reached
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line); // Print each line
        free(line); // Free the allocated memory for the line
    }

    // Close the file descriptor
    if (close(fd) < 0)
    {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}