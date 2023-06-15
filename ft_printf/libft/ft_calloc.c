/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:01:18 by kallegre          #+#    #+#             */
/*   Updated: 2022/11/20 11:23:06 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t s)
{
	void	*ptr;

	if (s == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	if (n > SIZE_MAX / s)
		return (NULL);
	ptr = malloc(n * s);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, n * s);
	return (ptr);
}
