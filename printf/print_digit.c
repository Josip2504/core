/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:13:15 by jsamardz          #+#    #+#             */
/*   Updated: 2024/03/21 16:14:59 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(long n, int base)
{
	int		i;
	char	*symbol;
	int		test;

	test = 0;
	i = 0;
	symbol = "0123456789abcdef";
	if (n < 0)
	{
		test += (write(1, "-", 1));
		if (test < 0)
			return (-1);
		return ((print_digit(-n, base) + 1));
	}
	else if (n < base)
	{
		return (print_char(symbol[n]));
	}
	else
	{
		i = print_digit(n / base, base);
		return (i + print_digit(n % base, base));
	}
}
