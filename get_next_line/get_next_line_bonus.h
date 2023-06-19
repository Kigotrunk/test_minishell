/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <kallegre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:42:12 by kallegre          #+#    #+#             */
/*   Updated: 2023/06/19 17:52:26 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int				end_of_line(char *str);
char			*get_next_line(int fd);
char			*join_read(char **str, int fd);
char			*cpy_reste(char *r);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*r_strcpy(char *src, char *dest);
char			*zmalloc(size_t n);
unsigned int	ft_strlen(const char *str);
char			*ft_strjoin_gnl(char *s1, char *s2);
char			*reste(char *src);
char			*cpyline(char *src);

#endif
