/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:10:56 by kallegre          #+#    #+#             */
/*   Updated: 2022/11/29 17:13:58 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		lennbr(int n);
static char		*minint(void);

char	*ft_itoa(int n)
{
	char	*nbr;
	int		negative;
	int		len;

	if (n == -2147483648)
		return (minint());
	negative = 0;
	if (n < 0)
	{
		n = -n;
		negative = 1;
	}
	len = lennbr(n) + negative;
	nbr = (char *)malloc(len + 1);
	if (nbr == NULL)
		return (NULL);
	nbr[len] = '\0';
	while (len - negative > 0)
	{
		nbr[--len] = n % 10 + '0';
		n /= 10;
	}
	if (negative)
		nbr[0] = '-';
	return (nbr);
}

static int	lennbr(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*minint(void)
{
	char	*nbr;

	nbr = (char *)malloc(12);
	ft_memmove(nbr, "-2147483648\0", 12);
	return (nbr);
}
