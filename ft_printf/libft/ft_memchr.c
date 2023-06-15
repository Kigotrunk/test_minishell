/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:22:15 by kallegre          #+#    #+#             */
/*   Updated: 2022/11/16 15:03:17 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem, int c, int n)
{
	int		i;
	char	*ptr;

	ptr = (char *)mem;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (char)c)
			return (ptr + i);
		i++;
	}
	return (0);
}
