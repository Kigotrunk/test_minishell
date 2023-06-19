/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <kallegre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:45:31 by kallegre          #+#    #+#             */
/*   Updated: 2023/06/19 17:52:16 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*r_strcpy(char *src, char *dest)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*cpyline(char *src)
{
	char	*str;
	int		i;

	i = 0;
	while (src[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		str[i] = src[i];
		i--;
	}
	return (str);
}

char	*ft_strjoin_gnl(char *str, char *buffer)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	new = (char *)malloc(ft_strlen(str) + i + 1);
	new[ft_strlen(str) + i] = '\0';
	i = 0;
	if (str != NULL)
	{
		i--;
		while (str[++i])
			new[i] = str[i];
	}
	j = -1;
	while (buffer[++j] && buffer[j] != '\n')
		new[i + j] = buffer[j];
	if (buffer[j] == '\n')
		new[i + j] = '\n';
	free(str);
	return (new);
}

int	end_of_line(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*reste(char *src)
{
	char	*str;
	int		i;
	int		j;

	if (!end_of_line(src))
	{
		free(src);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (src[i] != '\n')
		i++;
	i++;
	if (src[i] == '\0')
	{
		free(src);
		return (NULL);
	}
	while (src[i + j])
		j++;
	str = malloc(j + 1);
	str = r_strcpy(src + i, str);
	free(src);
	return (str);
}
