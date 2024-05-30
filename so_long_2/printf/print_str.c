/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:12:22 by jsamardz          #+#    #+#             */
/*   Updated: 2024/03/21 15:47:46 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		return (write (1, "(null)", 6));
	}
	if (!str)
		return (-1);
	while (*str)
	{
		count += print_char((int)*str);
		if (count < 0)
			return (-1);
		++str;
	}
	return (count);
}
