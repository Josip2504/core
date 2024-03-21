/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:12:48 by jsamardz          #+#    #+#             */
/*   Updated: 2024/03/21 14:18:58 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(uintptr_t ptr, int base)
{
	int	len;

	len = 0;
	while (ptr)
	{
		len++;
		ptr /= base;
	}
	if (len == 0)
		len = 1;
	return (len);
}

void	put_ptr(uintptr_t ptr, int base)
{
	char	digit;

	if (ptr > 0)
	{
		put_ptr(ptr / base, base);
		if (ptr % base < 10)
			digit = ptr % base + '0';
		else
			digit = ptr % base - 10 + 'a';
		write (1, &digit, 1);
	}
}

int	print_ptr(unsigned long ptr, int base)
{
	int	print_len;

	print_len = 0;
	if ((void *)ptr == NULL)
	{
		ft_printf("0x0");
		return (3);
	}
	print_len += write(1, "0x", 2);
	if (print_len == 0)
		print_len += write (1, "0", 1);
	else
	{
		put_ptr(ptr, base);
		print_len += ptr_len(ptr, base);
	}
	return (print_len);
}
