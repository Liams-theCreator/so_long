/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:24:49 by imellali          #+#    #+#             */
/*   Updated: 2024/11/13 17:08:23 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dptr;
	unsigned char	*sptr;

	i = 0;
	dptr = (unsigned char *)dest;
	sptr = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest == src)
		return (dest);
	while (i < n)
	{
		dptr[i] = sptr[i];
		i++;
	}
	return (dest);
}
