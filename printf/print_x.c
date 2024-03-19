/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:44:18 by jsamardz          #+#    #+#             */
/*   Updated: 2024/03/19 15:29:07 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(long n, int base)
{
	int		i;
	char	*symbol;

	symbol = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_x(-n, base) + 1);
	}
	if (n < base)
		return (print_char(symbol[n]));
	else
	{
		i = print_x(n / base, base);
		return (i + print_x(n % base, base));
	}
}
