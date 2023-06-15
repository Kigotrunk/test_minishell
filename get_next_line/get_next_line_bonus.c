/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <kallegre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:44:15 by kallegre          #+#    #+#             */
/*   Updated: 2023/06/15 17:31:13 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*r[4096];
	char		*buffer;
	char		*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 4096)
		return (NULL);
	if (r[fd] != NULL)
	{
		if (end_of_line(r[fd]))
		{
			str = cpyline(r[fd]);
			r[fd] = reste(r[fd]);
			return (str);
		}
		else
			str = cpy_reste(r[fd]);
	}
	else
		str = NULL;
	buffer = join_read(&str, fd);
	r[fd] = reste(buffer);
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
		*str = ft_strjoin2(*str, buffer);
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
