/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:18:40 by kallegre          #+#    #+#             */
/*   Updated: 2022/12/05 21:15:51 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(va_list ptr)
{
	char	c;

	c = (char)va_arg(ptr, int);
	write(1, &c, 1);
}

unsigned int	print_p(va_list ptr)
{
	unsigned int	i;
	unsigned long	n;

	n = (unsigned long)va_arg(ptr, unsigned long);
	i = 2;
	write(1, "0x", 2);
	ptr_hexa(n, &i);
	return (i);
}

unsigned int	print_x(va_list ptr, int maj)
{
	int				n;
	unsigned int	i;

	n = (int)va_arg(ptr, int);
	i = 0;
	put_hexa(n, maj, &i);
	return (i);
}

void	ptr_hexa(unsigned long n, unsigned int *i)
{
	if (n >= 16)
	{
		ptr_hexa(n / 16, i);
		ptr_hexa(n % 16, i);
	}
	else
	{
		*i = *i + 1;
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
			ft_putchar_fd(n - 10 + 'a', 1);
	}
}

void	put_hexa(unsigned int n, int maj, unsigned int *i)
{
	if (n >= 16)
	{
		put_hexa(n / 16, maj, i);
		put_hexa(n % 16, maj, i);
	}
	else
	{
		*i = *i + 1;
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else if (maj == 1)
			ft_putchar_fd(n - 10 + 'A', 1);
		else
			ft_putchar_fd(n - 10 + 'a', 1);
	}
}
