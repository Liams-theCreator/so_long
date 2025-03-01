/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:27:41 by imellali          #+#    #+#             */
/*   Updated: 2024/11/12 19:17:47 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_compare(char chr, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == chr)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_copy(char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	char	*buff;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	len = ft_strlen(s1);
	while (ft_compare(s1[start], set) == 1 && s1[start] != '\0')
		start++;
	while (ft_compare(s1[len - 1], set) == 1)
		len--;
	if (len < start)
		return (ft_strdup(""));
	buff = malloc(sizeof(char) * ((len - start) + 1));
	if (buff == NULL)
		return (NULL);
	ft_copy(buff, s1 + start, len - start);
	return (buff);
}
