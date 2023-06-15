/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:09:05 by kallegre          #+#    #+#             */
/*   Updated: 2022/11/18 17:51:31 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	len(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	j = ft_strlen(dest);
	if (size <= j)
		return (size + ft_strlen(src));
	while (src[i] != '\0' && j + i < size - 1)
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (ft_strlen(src) + j);
}
