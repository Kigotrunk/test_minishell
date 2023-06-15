/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:47:01 by kallegre          #+#    #+#             */
/*   Updated: 2022/11/18 16:42:29 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *chr, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	ptr = (char *)str;
	if (!*chr)
		return (ptr);
	if (len == 0)
		return (NULL);
	i = 0;
	while (ptr[i] && i < len)
	{
		j = 0;
		while (ptr[i] == chr[j] && ptr[i] && i < len)
		{
			i++;
			j++;
		}
		if (ft_strlen(chr) == j)
			return (ptr + i - j);
		i = i - j + 1;
	}
	return (NULL);
}
