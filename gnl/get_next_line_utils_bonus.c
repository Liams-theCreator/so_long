/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:29:02 by imellali          #+#    #+#             */
/*   Updated: 2024/12/09 19:37:30 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == 0)
		return ((char *)&s[i]);
	return ((char *)0);
}

static size_t	ft_slcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	while (*src != '\0')
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
	return (srclen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == NULL)
		return (NULL);
	ft_slcpy(buffer, s1, len + 1);
	ft_slcpy(buffer + ft_strlen(s1), s2, len + 1 - ft_strlen(s1));
	return (buffer);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	idx;
	char	*substr;

	i = 0;
	idx = start;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	while (s[idx] != '\0' && i < len)
	{
		substr[i] = s[idx];
		i++;
		idx++;
	}
	substr[i] = '\0';
	return (substr);
}
