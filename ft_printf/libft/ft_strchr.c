/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:21:15 by kallegre          #+#    #+#             */
/*   Updated: 2022/11/16 16:10:52 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;
	char	cc;

	ptr = (char *)str;
	cc = (char)c;
	while (*ptr && *ptr != cc)
		ptr++;
	if (*ptr == cc)
		return (ptr);
	return (0);
}
