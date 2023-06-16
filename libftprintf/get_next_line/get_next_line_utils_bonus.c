/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:35:52 by bmuni             #+#    #+#             */
/*   Updated: 2022/11/10 18:51:47 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlenn(char *s, int c)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c && c != '\0')
		i++;
	return (i);
}

int	ft_check_stat(char **s, int i)
{
	int	a;

	a = -1;
	if (i == 0)
	{
		while (++a < 1024)
		{
			if (s[a] != NULL || !(!s[a]))
				return (1);
		}
		return (0);
	}
	while (++a < 1024)
		free(s[a]);
	return (0);
}

void	*ft_calloc(size_t dim, size_t num)
{
	char	*ret;
	size_t	i;

	ret = malloc(dim * num);
	if (!ret)
	{
		free(ret);
		return (NULL);
	}
	i = -1;
	while (++i < num)
		ret[i] = '\0';
	return (ret);
}

char	*ft_strcpyfr(char *dest, char *src)
{
	int	i;

	i = -1;
	free(dest);
	dest = ft_calloc(1, ft_strlenn(src, '\0') + 1);
	if (src == NULL)
		return (dest);
	while (src[++i])
		dest[i] = src[i];
	free(src);
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if (src == NULL)
	{
		free(src);
		return (NULL);
	}
	dest = ft_calloc(1, ft_strlenn(src, '\n') + 1);
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}
