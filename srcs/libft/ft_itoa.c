/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:24:16 by imellali          #+#    #+#             */
/*   Updated: 2024/11/11 20:54:53 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = num * -1;
		len++;
	}
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static void	ft_insert(char *buffer, int n, size_t len)
{
	size_t	i;
	long	nbr;

	i = 0;
	nbr = n;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		buffer[len - 1] = '-';
	}
	while (nbr != 0)
	{
		buffer[i] = (nbr % 10) + '0';
		i++;
		nbr /= 10;
	}
}

static void	ft_swap(char *s1, size_t len)
{
	size_t	i;
	char	tmp;

	i = 0;
	while (i < len)
	{
		tmp = s1[i];
		s1[i] = s1[len - 1];
		s1[len - 1] = tmp;
		len--;
		i++;
	}
	s1[len + i] = '\0';
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*buffer;

	len = ft_intlen(n);
	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == NULL)
		return (NULL);
	if (n == 0)
	{
		buffer[0] = n + '0';
		buffer[1] = '\0';
		return (buffer);
	}
	ft_insert(buffer, n, len);
	ft_swap(buffer, len);
	return (buffer);
}
