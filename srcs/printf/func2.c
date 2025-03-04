/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:07:22 by imellali          #+#    #+#             */
/*   Updated: 2024/11/20 15:31:26 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_phelper(unsigned long long nptr)
{
	unsigned long long	remainder;
	int					printed;

	printed = 0;
	if (nptr / 16)
		printed += ft_phelper(nptr / 16);
	remainder = nptr % 16;
	if (remainder >= 10)
		printed += ft_printc((remainder - 10) + 'a');
	else
		printed += ft_printc(remainder + '0');
	return (printed);
}

int	ft_printp(void *ptr)
{
	unsigned long long	nptr;
	int					printed;

	printed = 0;
	nptr = (unsigned long long)ptr;
	if (ptr == NULL)
		return (printed += ft_prints("(nil)"));
	printed += ft_printc('0');
	printed += ft_printc('x');
	printed += ft_phelper(nptr);
	return (printed);
}
