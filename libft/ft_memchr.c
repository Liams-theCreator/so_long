/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:24:25 by imellali          #+#    #+#             */
/*   Updated: 2024/11/13 11:30:44 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*pstr;
	unsigned char		chr;
	size_t				len;

	len = 0;
	if (s == NULL)
		return (0);
	pstr = (unsigned char *)s;
	chr = (unsigned char)c;
	while (len < n)
	{
		if (*pstr == chr)
			return ((void *)pstr);
		pstr++;
		len++;
	}
	return ((void *)0);
}
