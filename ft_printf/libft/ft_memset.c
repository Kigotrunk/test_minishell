/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:29:53 by kallegre          #+#    #+#             */
/*   Updated: 2022/11/16 15:04:29 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, int n)
{
	unsigned char	*ptr2;
	int				i;

	ptr2 = ptr;
	i = 0;
	while (i < n)
	{
		ptr2[i] = c;
		i++;
	}
	return (ptr);
}
