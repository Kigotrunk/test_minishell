/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:06:14 by kallegre          #+#    #+#             */
/*   Updated: 2022/11/16 16:12:39 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	char	cc;

	ptr = (char *)str;
	cc = (char)c;
	while (*ptr)
		ptr++;
	while (ptr > str && *ptr != cc)
		ptr--;
	if (*ptr == cc)
		return (ptr);
	return (0);
}
