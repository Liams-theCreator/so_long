/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:30:35 by imellali          #+#    #+#             */
/*   Updated: 2024/11/21 12:49:33 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_search(char spec, va_list args)
{
	if (spec == 's')
		return (ft_prints(va_arg(args, const char *)));
	if (spec == 'c')
		return (ft_printc(va_arg(args, int)));
	if (spec == 'd' || spec == 'i')
		return (ft_printd(va_arg(args, int)));
	if (spec == 'u')
		return (ft_printu(va_arg(args, unsigned int)));
	if (spec == 'x' || spec == 'X')
		return (ft_printx(va_arg(args, unsigned int), spec));
	if (spec == '%')
		return (ft_printc('%'));
	if (spec == 'p')
		return (ft_printp(va_arg(args, void *)));
	return (ft_printc('%') + ft_printc(spec));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		printed;

	i = 0;
	printed = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			printed += ft_search(str[i], args);
		}
		else
			printed += ft_printc(str[i]);
		i++;
	}
	va_end(args);
	return (printed);
}
