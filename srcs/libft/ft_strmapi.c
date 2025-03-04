/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:27:09 by imellali          #+#    #+#             */
/*   Updated: 2024/11/11 20:28:53 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*buffer;

	i = 0;
	j = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		buffer[j] = f(i, s[i]);
		j++;
		i++;
	}
	buffer[j] = '\0';
	return (buffer);
}
