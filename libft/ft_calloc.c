/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:23:02 by imellali          #+#    #+#             */
/*   Updated: 2024/11/12 19:16:54 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	fullsize;
	char	*buf;

	i = 0;
	fullsize = nmemb * size;
	if (nmemb != 0 && (fullsize / nmemb) != size)
		return (NULL);
	buf = malloc(fullsize);
	if (buf == NULL)
		return (NULL);
	while (i < fullsize)
	{
		buf[i] = 0;
		i++;
	}
	return (buf);
}
