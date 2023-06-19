/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_parsing_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kortolan <kortolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:18:15 by kortolan          #+#    #+#             */
/*   Updated: 2023/06/19 16:49:00 by kortolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void echo_s_quote(int *in)
{
	if (*in == 0)
		*in = 1;	
	else
		*in = 0;
}

void echo_d_quote(int *in)
{
	if (*in == 0)
		*in = 2;
	else
		*in = 0;
}

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
	 c == '\v' || c == '\f' || c == '\r' || c == '\0')
	 	return (1);
	return (0);
}

int ft_is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return 1;
	return (0);
}

// char	*ft_str_add(char *tmp, char c)
// {
// 	char	*str;
// 	int		i;

// 	i = 0;
// 	ft_printf("in_ft_str_add\n");
// 	str = malloc((ft_strlen(tmp) + 2) * sizeof(char));
// 	ft_printf("test2\n");
// 	if(!str)
// 		return(NULL);
// 	ft_printf("in_ft_str_add_2\n");
// 	while (i != (int)ft_strlen(tmp))
// 	{
// 		str[i] = tmp[i];
// 		i++;
// 	}
// 	ft_printf("in_ft_str_add_3\n");
// 	str[i] = c;
// 	i++;
// 	str[i] = '\0'; 
// 	return (str);
// }