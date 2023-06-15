/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:56:31 by kallegre          #+#    #+#             */
/*   Updated: 2022/12/05 21:08:35 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int				ft_printf(const char *str, ...);
void			print_c(va_list ptr);
unsigned int	print_s(va_list ptr);
unsigned int	print_p(va_list ptr);
unsigned int	print_d(va_list ptr);
unsigned int	print_i(va_list ptr);
unsigned int	print_u(va_list ptr);
unsigned int	print_x(va_list ptr, int maj);
void			ptr_hexa(unsigned long n, unsigned int *i);
void			put_hexa(unsigned int n, int maj, unsigned int *i);

#endif
