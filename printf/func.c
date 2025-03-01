/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:41:34 by imellali          #+#    #+#             */
/*   Updated: 2024/11/20 15:31:34 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printc(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printd(int n)
{
	int	printed;

	printed = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		printed += ft_printc('-');
		n = n * -1;
	}
	if (n >= 10)
		printed += ft_printd(n / 10);
	printed += ft_printc((n % 10) + '0');
	return (printed);
}

int	ft_prints(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		ft_printc(str[i]);
		i++;
	}
	return (i);
}

int	ft_printu(unsigned int n)
{
	int	printed;

	printed = 0;
	if (n / 10)
		printed += ft_printu(n / 10);
	printed += ft_printc((n % 10) + '0');
	return (printed);
}

int	ft_printx(unsigned int n, char spec)
{
	int				printed;
	unsigned int	remain;

	printed = 0;
	remain = 0;
	if (n / 16)
		printed += ft_printx(n / 16, spec);
	remain = n % 16;
	if (remain >= 10)
	{
		if (spec == 'x')
			printed += ft_printc((remain - 10) + 'a');
		else
			printed += ft_printc((remain - 10) + 'A');
	}
	else
		printed += ft_printc(remain + '0');
	return (printed);
}
