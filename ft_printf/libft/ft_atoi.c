/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:47:27 by kallegre          #+#    #+#             */
/*   Updated: 2022/11/15 18:26:49 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nbr)
{
	int		value;
	int		signe;
	char	*str;

	str = (char *)nbr;
	value = 0;
	signe = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		value *= 10;
		value += *str - '0';
		str++;
	}
	return (signe * value);
}
