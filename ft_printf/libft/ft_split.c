/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:46:43 by kallegre          #+#    #+#             */
/*   Updated: 2022/11/18 16:19:54 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_word(const char *str, char charset);
int		word_len(const char *str, char charset);
int		sep_count(const char *str, char charset);
int		is_charset(char c, char charset);
char	**ft_split(const char *s, char c);

int	is_charset(char c, char charset)
{
	if (charset == c)
		return (1);
	return (0);
}

int	sep_count(const char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (is_charset(str[i], charset))
			i++;
		if (str[i])
		{
			count++;
			while (!is_charset(str[i], charset) && str[i])
				i++;
		}
	}
	return (count);
}

int	word_len(const char *str, char charset)
{
	int	i;

	i = 0;
	while (!is_charset(str[i], charset) && str[i])
		i++;
	return (i);
}

char	*get_word(const char *str, char charset)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	len = word_len(str, charset);
	line = (char *)malloc((len + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		ac;
	int		i;

	ac = sep_count(s, c);
	tab = (char **)malloc((ac + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (is_charset(*s, c))
			s++;
		if (*s)
		{
			tab[i] = get_word(s, c);
			i++;
		}
		while (!is_charset(*s, c) && *s)
			s++;
	}
	tab[i] = 0;
	return (tab);
}
