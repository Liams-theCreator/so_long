/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:24:38 by imellali          #+#    #+#             */
/*   Updated: 2024/11/13 11:09:52 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*ts1;
	unsigned const char	*ts2;
	size_t				i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	while (i < n)
	{
		if (*ts1 != *ts2)
			return (*ts1 - *ts2);
		i++;
		ts1++;
		ts2++;
	}
	return (0);
}
