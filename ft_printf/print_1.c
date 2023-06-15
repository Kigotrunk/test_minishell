/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:53:43 by kallegre          #+#    #+#             */
/*   Updated: 2022/12/05 20:04:52 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_unsigned_int(unsigned int n, unsigned int *i);
static void	put_int(int n, unsigned int *i);

unsigned int	print_s(va_list ptr)
{
	char			*str;
	unsigned int	i;

	str = (char *)va_arg(ptr, char *);
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

unsigned int	print_i(va_list ptr)
{
	int				nb;
	unsigned int	i;
	unsigned int	*p;

	nb = (int)va_arg(ptr, int);
	i = 0;
	p = &i;
	put_int(nb, p);
	return (i);
}

unsigned int	print_u(va_list ptr)
{
	unsigned int	nb;
	unsigned int	i;
	unsigned int	*p;

	nb = (unsigned int)va_arg(ptr, int);
	i = 0;
	p = &i;
	put_unsigned_int(nb, p);
	return (i);
}

static void	put_int(int n, unsigned int *i)
{
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		*i += 11;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		*i += 1;
		put_int(-n, i);
	}
	else if (n >= 10)
	{
		put_int(n / 10, i);
		put_int(n % 10, i);
	}
	else
	{
		ft_putchar_fd(n + '0', 1);
		*i += 1;
	}
}

static void	put_unsigned_int(unsigned int n, unsigned int *i)
{
	if (n >= 10)
	{
		put_unsigned_int(n / 10, i);
		put_unsigned_int(n % 10, i);
	}
	else
	{
		ft_putchar_fd(n + '0', 1);
		*i += 1;
	}
}
