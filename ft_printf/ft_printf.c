/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:25:52 by kallegre          #+#    #+#             */
/*   Updated: 2022/12/05 21:12:01 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			is_true(char c);
static unsigned int	lstprint(va_list ptr, char c);

int	ft_printf(const char *str, ...)
{
	int				i;
	unsigned int	total;
	va_list			ptr;	

	i = 0;
	total = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (is_true(str[i]))
				total += lstprint(ptr, str[i]);
			else
				i--;
		}
		else
		{
			write(1, &str[i], 1);
			total++;
		}
		i++;
	}
	return (total);
}

static int	is_true(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static unsigned int	lstprint(va_list ptr, char c)
{
	unsigned int	i;

	i = 1;
	if (c == 'c')
		print_c(ptr);
	else if (c == 's')
		return (print_s(ptr));
	else if (c == 'p')
		return (print_p(ptr));
	else if (c == 'd')
		return (print_i(ptr));
	else if (c == 'i')
		return (print_i(ptr));
	else if (c == 'u')
		return (print_u(ptr));
	else if (c == 'x')
		return (print_x(ptr, 0));
	else if (c == 'X')
		return (print_x(ptr, 1));
	else if (c == '%')
		write(1, "%", 1);
	return (i);
}
