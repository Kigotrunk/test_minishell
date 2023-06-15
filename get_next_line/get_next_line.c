/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:07:14 by kallegre          #+#    #+#             */
/*   Updated: 2022/12/06 16:45:20 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*r;
	char		*buffer;
	char		*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 4096)
		return (NULL);
	if (r != NULL)
	{
		if (end_of_line(r))
		{
			str = cpyline(r);
			r = reste(r);
			return (str);
		}
		else
			str = cpy_reste(r);
	}
	else
		str = NULL;
	buffer = join_read(&str, fd);
	r = reste(buffer);
	return (str);
}

char	*join_read(char **str, int fd)
{
	int		rrv;
	char	*buffer;

	buffer = zmalloc(BUFFER_SIZE + 1);
	while (!end_of_line(*str))
	{
		rrv = read(fd, buffer, BUFFER_SIZE);
		if (rrv <= 0)
			break ;
		buffer[rrv] = '\0';
		*str = ft_strjoin(*str, buffer);
	}
	return (buffer);
}

char	*cpy_reste(char *r)
{
	char	*str;

	str = (char *)malloc(ft_strlen(r) + 1);
	str = r_strcpy(r, str);
	free(r);
	return (str);
}

unsigned int	ft_strlen(const char *str)
{
	unsigned int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*zmalloc(size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(n);
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
