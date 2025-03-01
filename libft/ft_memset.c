/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:25:05 by imellali          #+#    #+#             */
/*   Updated: 2024/11/13 10:27:42 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	val;
	unsigned char	*buf;
	size_t			i;

	val = (unsigned char)c;
	buf = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		buf[i] = val;
		i++;
	}
	return (b);
}
