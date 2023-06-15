/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:15:30 by kallegre          #+#    #+#             */
/*   Updated: 2022/11/18 18:20:16 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*dest2;
	const char		*src2;

	if (!dest && !src)
		return (NULL);
	dest2 = (char *)dest;
	src2 = (const char *)src;
	if (src < dest)
	{
		while (n-- > 0)
			dest2[n] = src2[n];
		return (dest2);
	}
	else
		return (ft_memcpy(dest, src, n));
}
