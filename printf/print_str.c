/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:12:22 by jsamardz          #+#    #+#             */
/*   Updated: 2024/03/20 15:43:24 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
	{
		ft_printf("(null)");
		return (6);
	}
	while (*str)
	{
		print_char((int)*str);
		++i;
		++str;
	}
	return (i);
}
