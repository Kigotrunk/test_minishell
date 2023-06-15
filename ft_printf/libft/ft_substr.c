/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:02:54 by kallegre          #+#    #+#             */
/*   Updated: 2022/12/03 15:56:21 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	l;
	unsigned int	i;
	char			*str;

	l = 0;
	while (start < ft_strlen(s) && s[start + l] && l < len)
		l++;
	str = malloc(l + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
