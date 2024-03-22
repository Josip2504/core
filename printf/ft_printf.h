/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:34:01 by jsamardz          #+#    #+#             */
/*   Updated: 2024/03/22 11:50:34 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
int		print_format(char spec, va_list ap);
int		print_char(int c);
int		print_str(char *str);
int		print_digit(long n, int base);
int		print_x(long n, int base);
int		print_ptr(unsigned long ptr, int base);

#endif