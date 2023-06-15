/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallegre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:46:30 by kallegre          #+#    #+#             */
/*   Updated: 2022/12/06 16:46:55 by kallegre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
char			*ft_strjoin(char *s1, char *s2);
char			*reste(char *src);
char			*cpyline(char *src);

#endif
