/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:34:25 by bmuni             #+#    #+#             */
/*   Updated: 2022/10/23 01:38:29 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
