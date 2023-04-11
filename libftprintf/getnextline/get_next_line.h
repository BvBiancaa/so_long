/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:33:11 by bmuni             #+#    #+#             */
/*   Updated: 2022/11/06 13:38:31 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, int *c);
int		presente(const char *s, int c);
size_t	ft_strlenn(char *s, int c);
void	*ft_calloc(size_t num, size_t dim);
char	*ft_strcpyfr(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
char	*ft_stat(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif
