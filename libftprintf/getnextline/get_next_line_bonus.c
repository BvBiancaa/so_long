/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:45:12 by bmuni             #+#    #+#             */
/*   Updated: 2022/11/10 18:56:55 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (!s1)
		s1 = ft_calloc(sizeof(char), 1);
	if (s2 == NULL)
		return (s1);
	s3 = ft_calloc(1, (ft_strlenn(s1, '\0') + ft_strlenn(s2, '\0') + 1));
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	j = -1;
	while (s2[++j])
		s3[i + j] = s2[j];
	free(s2);
	s1 = ft_strcpyfr(s1, s3);
	return (s1);
}

char	*ft_stat(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	str = ft_calloc(sizeof(char), (ft_strlenn(s, '\0') - i));
	j = 0;
	while (s[++i])
		str[j++] = s[i];
	free(s);
	return (str);
}

int	presente(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	if (c == 0)
		return (1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read(int fd, int *c)
{
	ssize_t	size;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	size = read(fd, buff, BUFFER_SIZE);
	if (size < 0)
	{
		*c = -1;
		free(buff);
		return (NULL);
	}
	*c = size;
	buff[size] = '\0';
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*mem[1024];
	char		*buff;
	int			c;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	c = 1;
	while (presente(mem[fd], c) == 0)
	{
		buff = ft_read(fd, &c);
		if ((c == -1 || c == 0) && (mem[fd] == NULL || buff == NULL))
		{
			free(buff);
			return (NULL);
		}
		mem[fd] = ft_strjoin_gnl(mem[fd], buff);
	}
	if (ft_check_stat(mem, 0) == 0)
	{
		ft_check_stat(mem, 1);
		return (NULL);
	}
	buff = ft_strcpy(buff, mem[fd]);
	mem[fd] = ft_stat(mem[fd]);
	return (buff);
}
