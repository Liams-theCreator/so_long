/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:26:31 by imellali          #+#    #+#             */
/*   Updated: 2024/11/11 15:04:09 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == NULL)
		return (NULL);
	ft_slcpy(buffer, s1, len + 1);
	ft_strlcat(buffer, s2, len + 1);
	return (buffer);
}
