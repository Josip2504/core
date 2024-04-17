/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:14:10 by jsamardz          #+#    #+#             */
/*   Updated: 2024/04/17 14:27:58 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i = 7;
	unsigned char mask = 1;
	unsigned char bit;

	while (i >= 0)
	{
		bit = (((octet >> i) & mask) + '0');
		write (1, &bit, 1);
		i--;
	}
}
