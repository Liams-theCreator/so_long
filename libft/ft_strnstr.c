/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:27:28 by imellali          #+#    #+#             */
/*   Updated: 2024/11/07 12:27:30 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && little[j] != '\0' && i + j < len)
				j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return ((char *)0);
}
